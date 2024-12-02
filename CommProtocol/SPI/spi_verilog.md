Here’s a Verilog implementation of a basic SPI master module that accounts for different **Clock Polarity (CPOL)** and **Clock Phase (CPHA)** settings. This module will allow us to control the CPOL and CPHA modes dynamically.

In this example:
- The module will act as an SPI master, which will control the SCLK, MOSI, and SS lines.
- It will receive data and settings to transmit data on the MOSI line while receiving data on the MISO line.

Let’s go step-by-step through the code and how each setting is handled.

### Verilog Code for SPI Master Module

```verilog
module SPI_Master (
    input wire clk,            // System clock
    input wire reset,          // Reset signal
    input wire [7:0] data_in,  // Data to be sent to SPI slave
    output reg [7:0] data_out, // Data received from SPI slave
    input wire start,          // Start signal for transmission
    output reg busy,           // Busy flag
    output reg SCLK,           // SPI clock
    output reg MOSI,           // Master Out Slave In
    input wire MISO,           // Master In Slave Out
    output reg SS,             // Slave Select (active low)
    input wire CPOL,           // Clock polarity
    input wire CPHA            // Clock phase
);

    // Parameters and Registers
    reg [7:0] shift_reg;       // Shift register for MOSI data
    reg [2:0] bit_count;       // Bit counter (for 8-bit data)
    reg clk_en;                // Enable for SCLK toggle

    // Clock Divider for SCLK generation (adjust according to system clock)
    reg [3:0] clk_div;         // Divider for slower SCLK generation

    // State Machine States
    typedef enum reg [1:0] {
        IDLE = 2'b00,
        LOAD = 2'b01,
        TRANSFER = 2'b10,
        DONE = 2'b11
    } state_t;
    state_t state;

    // Clock Polarity and Phase Setup
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            SCLK <= CPOL;         // Set idle level for SCLK based on CPOL
            busy <= 1'b0;
            SS <= 1'b1;           // Set SS high (inactive) initially
        end else begin
            case (state)
                IDLE: begin
                    busy <= 1'b0;
                    SCLK <= CPOL;
                    SS <= 1'b1;    // Deactivate SS
                    if (start) begin
                        shift_reg <= data_in;  // Load data into shift register
                        bit_count <= 3'b111;   // Set counter for 8 bits
                        SS <= 1'b0;            // Activate SS (select slave)
                        busy <= 1'b1;
                        state <= LOAD;
                    end
                end

                LOAD: begin
                    // Start bit transfer based on CPHA
                    if (CPHA == 1'b0) begin
                        // Sample data on first clock edge
                        MOSI <= shift_reg[7];  // Set MOSI for MSB
                        clk_en <= 1'b1;
                    end else begin
                        // Wait for first clock cycle if CPHA = 1
                        clk_en <= 1'b0;
                    end
                    state <= TRANSFER;
                end

                TRANSFER: begin
                    // Toggle SCLK based on clock divider
                    if (clk_div == 4'b0000) begin
                        clk_en <= ~clk_en;
                        SCLK <= clk_en ? ~CPOL : CPOL;  // Toggle SCLK

                        if (clk_en == CPHA) begin
                            // Transmit on appropriate edge based on CPHA
                            MOSI <= shift_reg[7];
                            shift_reg <= {shift_reg[6:0], MISO};  // Shift in MISO data
                            bit_count <= bit_count - 1;
                        end

                        if (bit_count == 3'b000) begin
                            state <= DONE;
                        end
                    end

                    clk_div <= clk_div + 1;
                end

                DONE: begin
                    data_out <= shift_reg;  // Capture received data
                    busy <= 1'b0;
                    SS <= 1'b1;             // Deselect slave
                    SCLK <= CPOL;           // Return SCLK to idle
                    state <= IDLE;
                end

                default: state <= IDLE;
            endcase
        end
    end
endmodule
```

### Explanation of Each Part

1. **Clock Polarity (CPOL) and Phase (CPHA) Control**:
   - `CPOL` determines the idle state of `SCLK`. The initial value of `SCLK` is set based on `CPOL`.
   - `CPHA` controls the sampling point. If `CPHA = 0`, data is sampled on the first clock edge (either rising or falling, depending on `CPOL`). If `CPHA = 1`, data is sampled on the second edge.

2. **State Machine**:
   - **IDLE**: The module waits for the `start` signal. Upon receiving it, it loads the data into a shift register, sets `SS` low to select the slave, and moves to `LOAD`.
   - **LOAD**: Initializes `MOSI` with the first bit of the shift register based on `CPHA`. If `CPHA = 0`, it immediately sets `MOSI`; if `CPHA = 1`, it waits for the first clock cycle.
   - **TRANSFER**: Manages the actual bit-by-bit data transfer. This involves toggling `SCLK` based on the clock enable (`clk_en`) signal, which is derived from the system clock divided down for slower `SCLK`.
   - **DONE**: Final state where it captures received data, sets `SS` high to deselect the slave, and returns `SCLK` to the idle state.

3. **Clock Division**:
   - `clk_div` is used to generate a slower `SCLK` from the system clock.
   - `clk_en` toggles at the required frequency to control when `SCLK` should toggle.

4. **MOSI and MISO Data Shifting**:
   - During each clock cycle in `TRANSFER`, the most significant bit (MSB) of `shift_reg` is sent out on `MOSI`, and `MISO` data is shifted in.
   - This shift continues until all bits have been transferred.

5. **Data Output**:
   - `data_out` holds the received data from the slave, which is updated in the `DONE` state after the transfer completes.

This implementation manages SPI transmission with selectable clock polarity and phase, making it adaptable to communicate with various devices. The design ensures timing is controlled by `CPOL` and `CPHA` to avoid data misinterpretation during transfers.
