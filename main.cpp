#include"packet.h"
#include"n_nary_tree.h"
#include"queue.h"

void main()
{
	n_nary_tree t1;
	Packet p0,p1,p2,p3;
	Packet p4,p5,p6,p7,p8,p9;
	linked_list_Queue queue(&t1);
	
	//n_nary_tree�� �̿� Routing table�� ����
	t1.enter_one("145.231.222.19",8);
	t1.enter_one("143.248.21.32",5); 
	t1.enter_one("143.248.92.100",1);
	t1.enter_one("142.211.130.121",2);
	t1.enter_one("141.248.121.100",1);
	t1.enter_one("211.100.11.1",3);
	t1.enter_one("105.32.111.5",4);
	t1.enter_one("212.100.130.5",3);
	t1.enter_one("213.10.10.5",5);
	t1.enter_one("143.248.221.32",1); 
	t1.enter_one("214.10.10.5",5);
	t1.enter_one("216.16.110.5",5);
	t1.enter_one("216.10.10.5",5);
	t1.enter_one("218.10.10.5",5); //top node�� 10���� �Ѿ�� error �޽��� ���
	
	//Routing table���� �Էµ� IP�� ã��
	cout<<t1.search_output_link("211.304.11.1")<<endl; //���� IP�� ã�⶧���� �����޽��� ��°� 0�� ����
	cout<<t1.search_output_link("211.100.11.1")<<endl; 
	cout<<t1.search_output_link("142.211.130.121")<<endl;
	t1.print(); //Routing table���

	//delete_one�� ����ؼ� ����
	t1.delete_one("214.10.10.5");
	t1.delete_one("213.10.10.5");
	t1.delete_one("214.10.10.5"); //���� IP�� ���� �� �����Ƿ� ���� �޽��� ���
	t1.print(); //������ Routing table���
	
	//packet �Է�
	p0.input_packet("145.231.222.19");
	p1.input_packet("143.248.92.100");
	p2.input_packet("143.248.121.100");
	p3.input_packet("143.248.221.32");
	p4.input_packet("142.211.130.121");
	p5.input_packet("211.100.11.1");
	p6.input_packet("105.32.111.5");
	p7.input_packet("141.248.121.100");
	p8.input_packet("214.10.10.5");
	p9.input_packet("216.10.10.5");

	//queue�� packet�Է�
	queue.push_queue(&p4);
	queue.push_queue(&p0);
	queue.push_queue(&p1);
	queue.push_queue(&p8); //���� IP�̹Ƿ� ���� �޽��� ���
	queue.push_queue(&p2); //���� IP�̹Ƿ� ���� �޽��� ���
	queue.push_queue(&p5);
	queue.push_queue(&p6);
	queue.push_queue(&p3);
	queue.push_queue(&p7);
	queue.push_queue(&p9);
	
	//�־��� ��¸�ũ��ȣ�� ������ queue���� ������ ����
	queue.output_queue(1);
	queue.output_queue(2);
	queue.output_queue(3);
	queue.output_queue(4);
	queue.output_queue(5);
	queue.output_queue(6); //output num : 6�� ������ �����Ƿ� ���� �޽��� ���
	queue.output_queue(8);
	
	//�־��� ��¸�ũ��ȣ�� ������ queue���� IP�ּҸ� ��� ���
	queue.print_queue(5);
	queue.print_queue(4);
	queue.print_queue(2);
	queue.print_queue(3);
	queue.print_queue(8);
	queue.print_queue(1);
	queue.print_queue(6); //output num : 6�� ������ �����Ƿ� ���� �޽��� ���

	queue.print_all(); //(�߰��Լ�) ��� queue���� �����
	
	queue.pop_up_queue(1); //��¸�ũ�� 1�� queue�� ù��° ��Ŷ�� pop_up��
	queue.pop_up_queue(3); //��¸�ũ�� 3�� queue�� ù��° ��Ŷ�� pop_up��
	queue.pop_up_queue(6); //output num : 6�� ������ �����Ƿ� ���� �޽��� ���
	queue.print_queue(1); //pop_up�� �ϰ� ���� ��¸�ũ��ȣ 1�� ������ ť�� ���
	queue.print_all(); //(�߰��Լ�) ��� queue���� �����
	
	queue.delete_all();  //(�߰��Լ�) ��� queue���� ������
	queue.print_all(); //queue���� �� ���������Ƿ� ����ٰ� ���

	t1.delete_all(); //Routing table�� ��� ������ ����
	t1.print(); //Routing table�� ������Ƿ� ����ٰ� ���
}
