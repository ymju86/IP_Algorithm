#ifndef _N_NARY_TREE_H_
#define _N_NARY_TREE_H_

#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<iomanip.h>

class n_nary_tree{
	class node{
		public:
			char data[10]; //IP�ּҸ� '.'���� �����Ͽ� ������ѳ��� ��
			int output_link; //��� ��ũ ��ȣ(4��° ��忡�� ��¸�ũ��ȣ�� ����)
		private:
			node *direc[11]; //tree�� 10���� ���� ���(direc[10]�� �׻� NULL)
			node(void){
				for(int i=0; i<11; i++)
					direc[i]=NULL;
				strcpy(data,"");
				output_link=0;
			} //�⺻ ������			
		friend class n_nary_tree;
	};
	public:
		node *top[11]; //tree�� ó�� ���� ���(top[10]�� �׻� NULL)
		n_nary_tree(void){
			for(int i=0; i<11; i++)
				top[i]=NULL;
		} //�⺻ ������
		void enter_one(char ip_address[], int output_link);
		//IP�ּҿ� ��¸�ũ ��ȣ�� �Է¹޾� ����� ���̺� �߰�
		void enter(node *direc, char *adr, int output_link);
		//�߰��� �Լ�: enter_one�� ����Ҷ� ����Լ��� �̿� �ڵ带 ���̴� �Լ�
		
		// char *strchr(char *string_ptr, char find); 
		// �߰��� �Լ�: ���ϴ� ĳ������ ��ġ�� ã�� �����ͷ� ������
		
		int search_output_link(char ip_address[]); 
		//Ư�� IP�ּҸ� ���� ��Ŷ�� ������ ����� ���̺��� ã�Ƽ� �ش縵ũ ��ȣ�� ����
		void delete_one(char ip_address[]);
		//�Է¹��� IP�ּҸ� ����� ���̺��� ����
		void delete_all(void);
		//��� ����� ���̺��� entry�� ����
		void print(void);
		//����� ���̺� �Էµ� IP�ּҿ� �ش� ��¸�ũ��ȣ�� ���.
};

#endif