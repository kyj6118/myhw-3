#include <sys/types.h>
#include <limits.h>

#include "run.h"
#include "util.h"

void *base = 0;

p_meta head =0;
p_meta last =0;


p_meta find_meta(p_meta *last, size_t size) {
  p_meta index = base;
  p_meta result = base;

  switch(fit_flag){
    case FIRST_FIT:
    {

      //FIRST FIT CODE
if((*last)==0) {return 0;}
index=(*last)->prev;

while(index){

if(index->free==0||index->size<size)
index=index->prev;
else{
result=index;
break;
     }
  }
}  
    break;

    case BEST_FIT:
    {
      //BEST_FIT CODE

    p_meta temp=0;
  size_t m=9999;
while(index){

if(index ->free==0 && index->size>=size && index->size<m){
	temp=index;
	m=index->size;
}
index= index->next;   
 }
	result =temp;
}

    break;


    case WORST_FIT:
    {
      //WORST_FIT CODE

  }
  return result;

}}

void *m_malloc(size_t size) {
p_meta new=base;
p_meta prev=base;
p_meta temp=base;
p_meta next=base;

if(new= find_meta(&last,size)){
    if((new->size) > (size + META_SIZE)){
	next = new->next;
	temp->prev =new;
	temp ->next =next;
	temp->size = (new->size)-META_SIZE;
	temp->free=1;
	new->next=temp;
	next->prev =temp;
	 }

	(new ->free)=0;
return (new+META_SIZE);
} 


else {
	new =sbrk(META_SIZE);
	sbrk(size);
	
	new->next = last;
	new->prev =temp;
	temp->next =new;
	last->prev=new;
	new->size=size;
	new-> free = 0;
	return(new + META_SIZE);
	}
}

void m_free(void *ptr) {

}

void*
m_realloc(void* ptr, size_t size)
{

}
