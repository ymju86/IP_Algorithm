#ifndef _PACKET_H_
#define _PACKET_H_

#include<stdlib.h>
#include<string.h>
#include<iostream.h>

class Packet{
	friend class linked_list_Queue;
	private:
		char ip_address[20]; //IP�ּ�
	public:
		Packet(void){strcpy(ip_address,"");} //�⺻ ������
		void input_packet(char ip_address[]); 
		//�ش� IP�ּҸ� ������ ��Ŷ�ϳ��� �߻���Ű�� �Լ�
};
		
#endif