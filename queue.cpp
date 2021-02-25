#include"queue.h"

void linked_list_Queue::push_queue(Packet *p)
{
	char *tmp;
	tmp=p->ip_address;

	int output=r_table->search_output_link(tmp); //들어온 패킷의 output번호를 찾는다
	if(output==0)
	{	//들어온 패킷이 라우팅 테이블에 없는거면 리턴값이 0이므로 종료시킨다
		return;
	}

	int fn; //시작 queue의 포인터 number
	
	for(fn=0; fn<100 && first[fn]!=NULL && first[fn]->output_link!=output; fn++);
		//같은 출력링크번호를 가진 first queue를 찾음

	if(fn==100){ //100개가 넘는데도 같은것이 없으면 꽉 차 있으므로 더 추가시킬수 없다
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"linked_list_Queue's first node is full!!"<<endl;
		return;
	}
	
	if(first[fn]==NULL){ //같은output num을 가진 first queue가 없으면 새로 만든다
		first[fn] = new queue;
		first[fn]->output_link=output;
		first[fn]->data=p;
		first[fn]->size++; //추가하고 queue의 크기를 1증가 시킴
		cout<<"queue is pushed"<<endl;
		return;
	}

	if(first[fn]->size==100){ //같은output num을 가지는 큐가 100개가 넘으면 중지
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"linked_list_Queue's output num "<<output<<" is full!!"<<endl;
		return;
	}
	
	find(first[fn],first[fn]->size,fn,p); 
	//재귀적 호출을 하여 같은 output num을 가지는 queue의 마지막에 도달하게 하는 함수(추가)
}

void linked_list_Queue::find(queue *finder,int size,int fn,Packet *p)
{	//queue의 마지막을 찾는 함수(추가함수)
	if(size==1)
	{	//size가 1이면 마지막 queue이므로 새로운 queue를 만들어 들어온 packet을 저장시키고 종료한다.
		finder->next= new queue;
		finder->next->output_link=first[fn]->output_link;
		finder->next->data=p;
		first[fn]->size++; //추가하고 queue의 크기를 1증가 시킴
		cout<<"queue is pushed"<<endl;
		return;
	}
	else
	{
	int sz=size-1; //다음큐로 넘어가면서 count를 하나 줄인다
	find(finder->next,sz,fn,p);
	}
}

void linked_list_Queue::pop_up_queue(int output_link)
{
	int fn; //시작 queue의 포인터 number

	for(fn=0; fn<100 && first[fn]!=NULL && first[fn]->output_link!=output_link; fn++);
		//같은 출력링크번호를 가진 first queue를 찾음
	
	if(fn==100||first[fn]==NULL){ //같은output num을 가지지 않으면 중지
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"linked_list_Queue has not output num : "<<output_link<<endl;
		return;
	}
	
	queue *tmp_q; //first queue를 임시로 받아둘 변수
	tmp_q=first[fn]; 
	if(first[fn]->next!=NULL)
	{	//pop_up하고 그 출력링크번호를 가진 queue가 남아있을때
		first[fn]=first[fn]->next; //first queue의 다음큐를 first queue로 지정
		first[fn]->size=tmp_q->size-1; //size를 하나 줄임
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"pop up the queue has output num : "<<output_link<<endl;
		cout<<"IP is "<<tmp_q->data->ip_address<<endl;
		delete tmp_q; //임시로 받아 뒀던 원래의 first queue를 지움
	}
	else
	{	//pop_up하고 그 출력링크번호를 가진 queue가 남아있지 않을때
		int fns;
		for(fns=0; fns<100 && first[fns]!=NULL; fns++);
		for(; fn<fns; fn++)
		{	//지워진 queue들 뒤에 있는 queue들을 앞으로 당김
			first[fn]=first[fn+1];
		}
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"pop up the queue has output num : "<<output_link<<endl;
		cout<<"IP is "<<tmp_q->data->ip_address<<endl;
		delete tmp_q;
		delete first[fns];
		first[fns]=NULL; //지웠으니 NULL로 초기화를 시켜준다.
	}
}

void linked_list_Queue::output_queue(int output_link)
{
	int fn; //시작 queue의 포인터 number

	for(fn=0; fn<100 && first[fn]!=NULL && first[fn]->output_link!=output_link; fn++);
		//같은 출력링크번호를 가진 first queue를 찾음

	if(fn==100||first[fn]==NULL){ //같은output num을 가지지 않으면 중지
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"linked_list_Queue has not output num : "<<output_link<<endl;
		return;
	}
	cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"output num : "<<output_link<<" have "<<first[fn]->size<<" packet"<<endl;
	//first queue에 저장되어 있는 queue의 size를 출력
}

void linked_list_Queue::print_queue(int output_link)
{
	int fn; //시작 queue의 포인터 number

	for(fn=0; fn<100 && first[fn]!=NULL && first[fn]->output_link!=output_link; fn++);
		//같은 출력링크번호를 가진 first queue를 찾음

	if(fn==100||first[fn]==NULL){ //같은output num을 가지지 않으면 중지
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"linked_list_Queue has not output num : "<<output_link<<endl;
		return;
	}
	cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"Output num : "<<output_link<<" queue has following IP"<<endl;
	
	print(first[fn],first[fn]->size);
	//재귀함수 print를 호출
}

void linked_list_Queue::print(queue *printer,int size)
{	//재귀적 호출을 하면서 같은 output num을 가지는 큐들을 전부 출력한다(추가함수)
	if(size==1)
	{	//size가 1이면 마지막 queue이므로 출력하고 종료한다
		cout<<printer->data->ip_address<<endl;
		return;
	}
	cout<<printer->data->ip_address<<endl;

	int sz=size-1;
	print(printer->next,sz); 
	//자기자신을 호출(다음 queue를 부르면서 size값을 1줄인다)
}

void linked_list_Queue::print_all(void)
{	//linked_list에 있는 모든 queue들을 출력함(추가함수)
	cout<<"┏━━━━━━━━━━━━━━━━━━━┓"<<endl;
	cout<<"┃           Print all queue            ┃"<<endl;
	cout<<"┗━━━━━━━━━━━━━━━━━━━┛"<<endl;
	
	int fn;
	if(first[0]!=NULL)
	{	//첫번째 queue가 NULL이 아닐때 출력
		for(fn=0; fn<100 && first[fn]!=NULL; fn++)
		{
			cout<<"output num : "<<first[fn]->output_link<<" queue has following IP"<<endl;
			print(first[fn],first[fn]->size);
		}
	}
	else //모든 큐가 비었으므로 비었다고 출력
	cout<<"         linked_list is empty"<<endl;
}

void linked_list_Queue::delete_all(void)
{	//linked_list에 있는 모든 queue들을 제거함(추가함수)
	cout<<"┏━━━━━━━━━━━━━━━━━━━┓"<<endl;
	cout<<"┃           Delete all queue           ┃"<<endl;
	cout<<"┗━━━━━━━━━━━━━━━━━━━┛"<<endl;

	queue *new_ptr;
	queue *after_ptr;
	int fn;

	for(fn=0; fn<100 && first[fn]!=NULL; fn++)
	{
		after_ptr=first[fn]->next;
		new_ptr=first[fn];
		while(new_ptr!=NULL)
		{
			delete new_ptr;
			new_ptr=after_ptr;
			if(after_ptr!=NULL)
			after_ptr=after_ptr->next;
		}
		delete new_ptr;
		delete after_ptr;
	}
	for(int i=0; i<100; i++)
	{	//다 지웠으니 초기화
		first[i]=NULL;
	}
}