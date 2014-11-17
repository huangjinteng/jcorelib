#include <iostream>
#include <unistd.h>
//#include <Windows.h>
#define PEOPLE_SIZE 41
using namespace std;


struct People
{
    int id;
    People *forw;
    People *next;
};
People &init_people(int total,People*);
People &kill_all(People& first,int,int);
void recursion(People&);
void show(const People&);
int main()
{    
    	People *head,*tail;
	head = new People;
    	*head = init_people(PEOPLE_SIZE,head);
        *head = kill_all(*head,3,PEOPLE_SIZE);
    	show(*head);
    
    //while(temp != NULL){
        //cout << "1 delete" << temp->id << endl;
        
        //delete temp;
        //temp = temp->next;
    //}
        delete head;
    	return 0;
}


People &init_people(int total,People *head)
{
	int t = 0;
    	People *temp;
    	temp = head;
    	while(t < total)
    	{    
        	t++;                
        	temp->id = t;
        	if(t == total)break;    
        	temp->next = new People;
        	temp->next->forw = temp;
        	temp = temp->next;
    	}
    	temp->next = head;
    	head->forw = temp;
	return *head;
}


People &kill_all(People& first,int interval,int total)
{
	int current_size = total;
        int temp = 0;
        People *d_people;
	d_people = &first;
        while(current_size > 2)
        {
        	++temp;
        	if(temp % interval == 0)
        	{
                	d_people->forw->next = d_people->next;
			d_people->next->forw = d_people->forw;
			--current_size;
        	}
			d_people = d_people->next;
    	}
	return *d_people;
}


void recursion(People& p)
{
    
}


void show(const People& p)
{    
    People temp;
    temp = p;
    while(1)
    {
        cout << "id = " << temp.id << endl;
        temp = *(temp.next);
//Sleep(100);
usleep(1000 * 50);
    } 
} 



