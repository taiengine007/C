#include<stdio.h>
#include<pthread.h>

void * print_hello(void* args){
	
	printf("threadid--.>%ld\n",pthread_self());
}

int main(){



 pthread_t thread1,thread2;

 pthread_create(&thread1,NULL,print_hello,NULL);
 pthread_create(&thread2,NULL,print_hello,NULL);

 pthread_join(thread1,NULL);
 pthread_join(thread2,NULL);




return 0;
}
