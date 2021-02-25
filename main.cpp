#include"packet.h"
#include"n_nary_tree.h"
#include"queue.h"

void main()
{
	n_nary_tree t1;
	Packet p0,p1,p2,p3;
	Packet p4,p5,p6,p7,p8,p9;
	linked_list_Queue queue(&t1);
	
	//n_nary_tree를 이용 Routing table을 만듬
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
	t1.enter_one("218.10.10.5",5); //top node가 10개가 넘어가서 error 메시지 출력
	
	//Routing table에서 입력된 IP를 찾음
	cout<<t1.search_output_link("211.304.11.1")<<endl; //없는 IP를 찾기때문에 에러메시지 출력과 0값 리턴
	cout<<t1.search_output_link("211.100.11.1")<<endl; 
	cout<<t1.search_output_link("142.211.130.121")<<endl;
	t1.print(); //Routing table출력

	//delete_one을 사용해서 지움
	t1.delete_one("214.10.10.5");
	t1.delete_one("213.10.10.5");
	t1.delete_one("214.10.10.5"); //없는 IP를 지울 수 없으므로 에러 메시지 출력
	t1.print(); //지운후 Routing table출력
	
	//packet 입력
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

	//queue에 packet입력
	queue.push_queue(&p4);
	queue.push_queue(&p0);
	queue.push_queue(&p1);
	queue.push_queue(&p8); //없는 IP이므로 에러 메시지 출력
	queue.push_queue(&p2); //없는 IP이므로 에러 메시지 출력
	queue.push_queue(&p5);
	queue.push_queue(&p6);
	queue.push_queue(&p3);
	queue.push_queue(&p7);
	queue.push_queue(&p9);
	
	//주어진 출력링크번호를 가지는 queue들의 갯수를 구함
	queue.output_queue(1);
	queue.output_queue(2);
	queue.output_queue(3);
	queue.output_queue(4);
	queue.output_queue(5);
	queue.output_queue(6); //output num : 6은 가지지 않으므로 에러 메시지 출력
	queue.output_queue(8);
	
	//주어진 출력링크번호를 가지는 queue들의 IP주소를 모두 출력
	queue.print_queue(5);
	queue.print_queue(4);
	queue.print_queue(2);
	queue.print_queue(3);
	queue.print_queue(8);
	queue.print_queue(1);
	queue.print_queue(6); //output num : 6은 가지지 않으므로 에러 메시지 출력

	queue.print_all(); //(추가함수) 모든 queue들을 출력함
	
	queue.pop_up_queue(1); //출력링크가 1인 queue의 첫번째 패킷을 pop_up함
	queue.pop_up_queue(3); //출력링크가 3인 queue의 첫번째 패킷을 pop_up함
	queue.pop_up_queue(6); //output num : 6은 가지지 않으므로 에러 메시지 출력
	queue.print_queue(1); //pop_up을 하고 나서 출력링크번호 1을 가지는 큐를 출력
	queue.print_all(); //(추가함수) 모든 queue들을 출력함
	
	queue.delete_all();  //(추가함수) 모든 queue들을 제거함
	queue.print_all(); //queue들이 다 지워졌으므로 비었다고 출력

	t1.delete_all(); //Routing table의 모든 정보를 삭제
	t1.print(); //Routing table이 비었으므로 비었다고 출력
}
