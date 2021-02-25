#include"queue.h"

void linked_list_Queue::push_queue(Packet *p)
{
	char *tmp;
	tmp=p->ip_address;

	int output=r_table->search_output_link(tmp); //���� ��Ŷ�� output��ȣ�� ã�´�
	if(output==0)
	{	//���� ��Ŷ�� ����� ���̺� ���°Ÿ� ���ϰ��� 0�̹Ƿ� �����Ų��
		return;
	}

	int fn; //���� queue�� ������ number
	
	for(fn=0; fn<100 && first[fn]!=NULL && first[fn]->output_link!=output; fn++);
		//���� ��¸�ũ��ȣ�� ���� first queue�� ã��

	if(fn==100){ //100���� �Ѵµ��� �������� ������ �� �� �����Ƿ� �� �߰���ų�� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"linked_list_Queue's first node is full!!"<<endl;
		return;
	}
	
	if(first[fn]==NULL){ //����output num�� ���� first queue�� ������ ���� �����
		first[fn] = new queue;
		first[fn]->output_link=output;
		first[fn]->data=p;
		first[fn]->size++; //�߰��ϰ� queue�� ũ�⸦ 1���� ��Ŵ
		cout<<"queue is pushed"<<endl;
		return;
	}

	if(first[fn]->size==100){ //����output num�� ������ ť�� 100���� ������ ����
		cout<<"������������������������������������������"<<endl;
		cout<<"linked_list_Queue's output num "<<output<<" is full!!"<<endl;
		return;
	}
	
	find(first[fn],first[fn]->size,fn,p); 
	//����� ȣ���� �Ͽ� ���� output num�� ������ queue�� �������� �����ϰ� �ϴ� �Լ�(�߰�)
}

void linked_list_Queue::find(queue *finder,int size,int fn,Packet *p)
{	//queue�� �������� ã�� �Լ�(�߰��Լ�)
	if(size==1)
	{	//size�� 1�̸� ������ queue�̹Ƿ� ���ο� queue�� ����� ���� packet�� �����Ű�� �����Ѵ�.
		finder->next= new queue;
		finder->next->output_link=first[fn]->output_link;
		finder->next->data=p;
		first[fn]->size++; //�߰��ϰ� queue�� ũ�⸦ 1���� ��Ŵ
		cout<<"queue is pushed"<<endl;
		return;
	}
	else
	{
	int sz=size-1; //����ť�� �Ѿ�鼭 count�� �ϳ� ���δ�
	find(finder->next,sz,fn,p);
	}
}

void linked_list_Queue::pop_up_queue(int output_link)
{
	int fn; //���� queue�� ������ number

	for(fn=0; fn<100 && first[fn]!=NULL && first[fn]->output_link!=output_link; fn++);
		//���� ��¸�ũ��ȣ�� ���� first queue�� ã��
	
	if(fn==100||first[fn]==NULL){ //����output num�� ������ ������ ����
		cout<<"������������������������������������������"<<endl;
		cout<<"linked_list_Queue has not output num : "<<output_link<<endl;
		return;
	}
	
	queue *tmp_q; //first queue�� �ӽ÷� �޾Ƶ� ����
	tmp_q=first[fn]; 
	if(first[fn]->next!=NULL)
	{	//pop_up�ϰ� �� ��¸�ũ��ȣ�� ���� queue�� ����������
		first[fn]=first[fn]->next; //first queue�� ����ť�� first queue�� ����
		first[fn]->size=tmp_q->size-1; //size�� �ϳ� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"pop up the queue has output num : "<<output_link<<endl;
		cout<<"IP is "<<tmp_q->data->ip_address<<endl;
		delete tmp_q; //�ӽ÷� �޾� �״� ������ first queue�� ����
	}
	else
	{	//pop_up�ϰ� �� ��¸�ũ��ȣ�� ���� queue�� �������� ������
		int fns;
		for(fns=0; fns<100 && first[fns]!=NULL; fns++);
		for(; fn<fns; fn++)
		{	//������ queue�� �ڿ� �ִ� queue���� ������ ���
			first[fn]=first[fn+1];
		}
		cout<<"������������������������������������������"<<endl;
		cout<<"pop up the queue has output num : "<<output_link<<endl;
		cout<<"IP is "<<tmp_q->data->ip_address<<endl;
		delete tmp_q;
		delete first[fns];
		first[fns]=NULL; //�������� NULL�� �ʱ�ȭ�� �����ش�.
	}
}

void linked_list_Queue::output_queue(int output_link)
{
	int fn; //���� queue�� ������ number

	for(fn=0; fn<100 && first[fn]!=NULL && first[fn]->output_link!=output_link; fn++);
		//���� ��¸�ũ��ȣ�� ���� first queue�� ã��

	if(fn==100||first[fn]==NULL){ //����output num�� ������ ������ ����
		cout<<"������������������������������������������"<<endl;
		cout<<"linked_list_Queue has not output num : "<<output_link<<endl;
		return;
	}
	cout<<"������������������������������������������"<<endl;
	cout<<"output num : "<<output_link<<" have "<<first[fn]->size<<" packet"<<endl;
	//first queue�� ����Ǿ� �ִ� queue�� size�� ���
}

void linked_list_Queue::print_queue(int output_link)
{
	int fn; //���� queue�� ������ number

	for(fn=0; fn<100 && first[fn]!=NULL && first[fn]->output_link!=output_link; fn++);
		//���� ��¸�ũ��ȣ�� ���� first queue�� ã��

	if(fn==100||first[fn]==NULL){ //����output num�� ������ ������ ����
		cout<<"������������������������������������������"<<endl;
		cout<<"linked_list_Queue has not output num : "<<output_link<<endl;
		return;
	}
	cout<<"������������������������������������������"<<endl;
	cout<<"Output num : "<<output_link<<" queue has following IP"<<endl;
	
	print(first[fn],first[fn]->size);
	//����Լ� print�� ȣ��
}

void linked_list_Queue::print(queue *printer,int size)
{	//����� ȣ���� �ϸ鼭 ���� output num�� ������ ť���� ���� ����Ѵ�(�߰��Լ�)
	if(size==1)
	{	//size�� 1�̸� ������ queue�̹Ƿ� ����ϰ� �����Ѵ�
		cout<<printer->data->ip_address<<endl;
		return;
	}
	cout<<printer->data->ip_address<<endl;

	int sz=size-1;
	print(printer->next,sz); 
	//�ڱ��ڽ��� ȣ��(���� queue�� �θ��鼭 size���� 1���δ�)
}

void linked_list_Queue::print_all(void)
{	//linked_list�� �ִ� ��� queue���� �����(�߰��Լ�)
	cout<<"������������������������������������������"<<endl;
	cout<<"��           Print all queue            ��"<<endl;
	cout<<"������������������������������������������"<<endl;
	
	int fn;
	if(first[0]!=NULL)
	{	//ù��° queue�� NULL�� �ƴҶ� ���
		for(fn=0; fn<100 && first[fn]!=NULL; fn++)
		{
			cout<<"output num : "<<first[fn]->output_link<<" queue has following IP"<<endl;
			print(first[fn],first[fn]->size);
		}
	}
	else //��� ť�� ������Ƿ� ����ٰ� ���
	cout<<"         linked_list is empty"<<endl;
}

void linked_list_Queue::delete_all(void)
{	//linked_list�� �ִ� ��� queue���� ������(�߰��Լ�)
	cout<<"������������������������������������������"<<endl;
	cout<<"��           Delete all queue           ��"<<endl;
	cout<<"������������������������������������������"<<endl;

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
	{	//�� �������� �ʱ�ȭ
		first[i]=NULL;
	}
}