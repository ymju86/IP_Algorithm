#include"packet.h"

void Packet::input_packet(char i_ip_address[])
{
	strcpy(ip_address,i_ip_address);
	cout<<"������������������������������������������"<<endl;
	cout<<ip_address<<" packet added"<<endl;
}