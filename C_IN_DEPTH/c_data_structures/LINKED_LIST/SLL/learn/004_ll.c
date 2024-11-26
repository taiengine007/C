void display(struct node * start)
{
	struct node *p;
	
	if(start == NULL)
	{
	printf("list is empty\n");
	return ;
	}
	p = start;
	printf("list is : \n");

	while(p! = NULL)
	{
	 printf("%d ",p->info);
	 p = p->link;
	}
	printf("\n \n");

}
//////////////////////////////////////////////////
// count
//
void count(struct node* start)
{
 struct node* p;
 int cnt=0;
 p= start;

 while(p!=NULL)
 {
 p= p->link;
 cnt++;
 }
 printf("number of elemnents are --  %d\n",cnt);

}
//////////////////////////////////////////////////
// search
//
void search(struct node * start, int item)
{

  struct node* p = start;
  int pos=1;

  while(p!= NULL)
  {
     if(p->info == item)
     {
       printf("item %d found at position   %d\n",item,pos);
       return ;
     }
     p= p->link;
     pos++;
  
  
  }
  printf("item, not found \n");

}
