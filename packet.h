#ifndef _PACKET_H_
#define _PACKET_H_

#include<stdlib.h>
#include<string.h>
#include<iostream.h>

class Packet{
	friend class linked_list_Queue;
	private:
		char ip_address[20]; //IP주소
	public:
		Packet(void){strcpy(ip_address,"");} //기본 생성자
		void input_packet(char ip_address[]); 
		//해당 IP주소를 가지는 패킷하나를 발생시키는 함수
};
		
#endif