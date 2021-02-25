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
			} //기본 생성자
		private:
			queue *next; //다음 큐를 가르킴
			Packet *data; //queue가 받는 패킷
			int output_link; //출력 링크 번호(모든 큐마다 가지고 있음)
			int size; //큐에 연결된 패킷의 갯수 : 100개로 제한 걸기 위해 사용(first queue만 가지고 있음)
		friend class linked_list_Queue;
	};
	public:
		queue *first[100]; //시작 queue의 포인터, 100개의 출력 링크번호를 가진 queue저장가능
		n_nary_tree *r_table; //라우팅 태이블
		linked_list_Queue(void){
			for(int i=0; i<100; i++)
			first[i]=NULL;
		} //기본 생성자
		linked_list_Queue(n_nary_tree *tree){
			for(int i=0; i<100; i++)
			first[i]=NULL;
			r_table=tree;
		} //파라미터가 있는 생성자
		void push_queue(Packet *p);
		//패킷을 매개변수로 받아 해당패킷의 IP주소를 따라
		//출력 링크 번호 i번째 queue에 패킷을 삽입하는 역할을 하는 함수
		void find(queue *finder,int size,int fn,Packet *p);
		//재귀적 호출을 하여 같은 output num을 가지는 queue의 마지막에 도달하게 하는 함수(추가함수)
		void pop_up_queue(int output_link);
		//queue에 가장 먼저 들어온 패킷을 pop up하는 함수
		void output_queue(int output_link);
		//해당 출력 링크의 queue에 저장되어 있는 패킷의 수를 출력하는 함수
		void print_queue(int output_link);
		//해당 출력 링크의 queue에 들어있는 모든 패킷의 IP주소를 출력하는 역할을하는 함수
		void print(queue *printer,int size);
		//재귀적 호출을 하면서 같은 output num을 가지는 큐들을 전부 출력한다(추가함수)
		void print_all(void);
		//linked_list에 있는 모든 queue들을 출력함(추가함수)
		void delete_all(void);
		//linked_list에 있는 모든 queue들을 제거함(추가함수)
};

#endif