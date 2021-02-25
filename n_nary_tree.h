#ifndef _N_NARY_TREE_H_
#define _N_NARY_TREE_H_

#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<iomanip.h>

class n_nary_tree{
	class node{
		public:
			char data[10]; //IP주소를 '.'으로 구분하여 저장시켜놓은 값
			int output_link; //출력 링크 번호(4번째 노드에만 출력링크번호를 저장)
		private:
			node *direc[11]; //tree의 10가지 방향 노드(direc[10]은 항상 NULL)
			node(void){
				for(int i=0; i<11; i++)
					direc[i]=NULL;
				strcpy(data,"");
				output_link=0;
			} //기본 생성자			
		friend class n_nary_tree;
	};
	public:
		node *top[11]; //tree의 처음 시작 노드(top[10]은 항상 NULL)
		n_nary_tree(void){
			for(int i=0; i<11; i++)
				top[i]=NULL;
		} //기본 생성자
		void enter_one(char ip_address[], int output_link);
		//IP주소와 출력링크 번호를 입력받아 라우팅 태이블에 추가
		void enter(node *direc, char *adr, int output_link);
		//추가된 함수: enter_one을 사용할때 재귀함수를 이용 코드를 줄이는 함수
		
		// char *strchr(char *string_ptr, char find); 
		// 추가된 함수: 원하는 캐릭터의 위치를 찾아 포인터로 돌려줌
		
		int search_output_link(char ip_address[]); 
		//특정 IP주소를 가진 패킷이 들어오면 라우팅 테이블을 찾아서 해당링크 번호를 리턴
		void delete_one(char ip_address[]);
		//입력받은 IP주소를 라우팅 테이블에서 지움
		void delete_all(void);
		//모든 라우팅 테이블의 entry를 지움
		void print(void);
		//라우팅 테이블에 입력된 IP주소와 해당 출력링크번호를 출력.
};

#endif