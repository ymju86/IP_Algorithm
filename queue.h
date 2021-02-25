#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include"packet.h"
#include"n_nary_tree.h"

class linked_list_Queue{
	class queue{
		public:
			queue(void){
				output_link=0;
				next=NULL;
				data=NULL;
				size=0;
			} //�⺻ ������
		private:
			queue *next; //���� ť�� ����Ŵ
			Packet *data; //queue�� �޴� ��Ŷ
			int output_link; //��� ��ũ ��ȣ(��� ť���� ������ ����)
			int size; //ť�� ����� ��Ŷ�� ���� : 100���� ���� �ɱ� ���� ���(first queue�� ������ ����)
		friend class linked_list_Queue;
	};
	public:
		queue *first[100]; //���� queue�� ������, 100���� ��� ��ũ��ȣ�� ���� queue���尡��
		n_nary_tree *r_table; //����� ���̺�
		linked_list_Queue(void){
			for(int i=0; i<100; i++)
			first[i]=NULL;
		} //�⺻ ������
		linked_list_Queue(n_nary_tree *tree){
			for(int i=0; i<100; i++)
			first[i]=NULL;
			r_table=tree;
		} //�Ķ���Ͱ� �ִ� ������
		void push_queue(Packet *p);
		//��Ŷ�� �Ű������� �޾� �ش���Ŷ�� IP�ּҸ� ����
		//��� ��ũ ��ȣ i��° queue�� ��Ŷ�� �����ϴ� ������ �ϴ� �Լ�
		void find(queue *finder,int size,int fn,Packet *p);
		//����� ȣ���� �Ͽ� ���� output num�� ������ queue�� �������� �����ϰ� �ϴ� �Լ�(�߰��Լ�)
		void pop_up_queue(int output_link);
		//queue�� ���� ���� ���� ��Ŷ�� pop up�ϴ� �Լ�
		void output_queue(int output_link);
		//�ش� ��� ��ũ�� queue�� ����Ǿ� �ִ� ��Ŷ�� ���� ����ϴ� �Լ�
		void print_queue(int output_link);
		//�ش� ��� ��ũ�� queue�� ����ִ� ��� ��Ŷ�� IP�ּҸ� ����ϴ� �������ϴ� �Լ�
		void print(queue *printer,int size);
		//����� ȣ���� �ϸ鼭 ���� output num�� ������ ť���� ���� ����Ѵ�(�߰��Լ�)
		void print_all(void);
		//linked_list�� �ִ� ��� queue���� �����(�߰��Լ�)
		void delete_all(void);
		//linked_list�� �ִ� ��� queue���� ������(�߰��Լ�)
};

#endif