#include"n_nary_tree.h"

void n_nary_tree::enter_one(char ip_address[], int output_link)
{
	int tn; //top number
	int i;
	char tmp[10]; //임시로 IP주소를 받아둠
	
	for(i=0; ip_address[i]!='.'; i++)
	{	//처음 '.'이 나올때까지 IP주소를 임시변수에 저장
		tmp[i]=ip_address[i];
	}
	tmp[i]=NULL; //'.'을 NULL으로 변환

	for(tn=0; tn<10 && top[tn]!=NULL && strcmp(top[tn]->data,tmp)!=0; tn++);
		//같은 IP주소를 가진 top node를 찾음

	if(tn==10){ //10개가 넘는데도 같은것이 없으면 꽉 차 있으므로 더 추가시킬수 없다
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"Tree's top node is full!!"<<endl;
		return;
	}

	if(top[tn]==NULL){ //같은 IP를 가진 top node가 없으면 새로 만든다
		top[tn] = new node;
		strcpy(top[tn]->data,tmp);
	}

	enter(top[tn], &ip_address[i+1], output_link);
}

void n_nary_tree::enter(node *direc, char *adrs, int output_link)
{
	int dn; //direction number
	int i;
	char tmp[10]; //임시로 IP주소를 받아둠
	
	if(adrs[0]==NULL)
	{	//주소를 다 입력 시키고 나서 마지막 node에 출력링크 번호를 입력 시킨다
		direc->output_link=output_link;
		return;
	}

	for(i=0; adrs[i]!='.' && adrs[i]!=NULL; i++)
	{	//'.'이 나오거나 NULL일 때까지 IP주소를 임시변수에 저장
		tmp[i]=adrs[i];
	}
	tmp[i]=NULL; //'.'을 NULL으로 변환

	for(dn=0; dn<10 && direc->direc[dn]!=NULL && strcmp(direc->direc[dn]->data,tmp)!=0; dn++);
		//같은 IP주소를 가진 node를 찾음

	if(dn==10){ //10개가 넘는데도 같은것이 없으면 꽉 차 있으므로 더 추가시킬수 없다
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"Tree's node is full!!"<<endl;
		return;
	}

	if(direc->direc[dn]==NULL){ //같은 IP를 가진 node가 없으면 새로 만든다
		direc->direc[dn] = new node;
		strcpy(direc->direc[dn]->data,tmp);		
	}
	enter(direc->direc[dn], adrs+i+1, output_link); 
	//마지막 IP주소까지 다 입력 시킬때 까지 자기자신을 호출

}

char *strchr(char *string_ptr, char find) 
{  //수업 시간에 배운 함수, 원하는 캐릭터의 위치를 찾음.
	while (*string_ptr != find) 
	{
		if (*string_ptr == NULL)
		return (NULL);	// not found 
		++string_ptr;
	}
    return (string_ptr);	// Found 
}

int n_nary_tree::search_output_link(char ip_address[])
{
	char tmp[20]; //임시로 IP주소를 받아둠
	char *tmp_ptr0; //첫번째 숫자열
	char *tmp_ptr1; //두번째 숫자열
	char *tmp_ptr2; //세번째 숫자열
	char *tmp_ptr3; //네번째 숫자열

	strcpy(tmp,ip_address);
	tmp_ptr0 = tmp;
	tmp_ptr1 = strchr(tmp,'.'); //ip_address에서 '.'을 찾음
	*tmp_ptr1 = NULL; //'.'을 null로 바꿈 
	++tmp_ptr1; //null 다음을 가르킴
	tmp_ptr2 = strchr(tmp_ptr1,'.'); //위와 같은 방법
	*tmp_ptr2 = NULL;
	++tmp_ptr2;
	tmp_ptr3 = strchr(tmp_ptr2,'.'); //위와 같은 방법
	*tmp_ptr3 = NULL;
	++tmp_ptr3;

	int k,ks; //top node 상수
	int j,js; //2번째 node 상수
	int l,ls; //3번째 node 상수
	int m,ms; //4번째 node 상수

	for(ks=0; ks<10 && top[ks]!=NULL; ks++); //NULL이 아닐때까지의 탑노드의 갯수를 찾음
	for(k=0; k<ks && strcmp(top[k]->data,tmp_ptr0)!=0; k++); //입력된 ip와 같을때까지 비교
	if(k==ks) 
	{	//같은 ip가 존재하지 않음
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"I can't search IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return (0);
	}
	for(js=0; js<10 && top[k]->direc[js]!=NULL; js++); //NULL이 아닐때까지의 노드의 갯수를 찾음
	for(j=0; j<js && strcmp(top[k]->direc[j]->data,tmp_ptr1)!=0; j++); //입력된 ip와 같을때까지 비교
	if(j==js) 
	{	//같은 ip가 존재하지 않음
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"I can't search IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return (0);
	}
	for(ls=0; ls<10 && top[k]->direc[j]->direc[ls]!=NULL; ls++); //NULL이 아닐때까지의 노드의 갯수를 찾음
	for(l=0; l<ls && strcmp(top[k]->direc[j]->direc[l]->data,tmp_ptr2)!=0; l++); //입력된 ip와 같을때까지 비교
	if(l==ls) 
	{	//같은 ip가 존재하지 않음
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"I can't search IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return (0);
	}
	for(ms=0; ms<10 && top[k]->direc[j]->direc[l]->direc[ms]!=NULL; ms++); //NULL이 아닐때까지의 노드의 갯수를 찾음
	for(m=0; m<ms && strcmp(top[k]->direc[j]->direc[l]->direc[m]->data,tmp_ptr3)!=0; m++); //입력된 ip와 같을때까지 비교
	if(m==ms) 
	{	//같은 ip가 존재하지 않음
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"I can't search IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return (0);
	}

	cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"We found IP Address : "<<ip_address<<endl;
	return(top[k]->direc[j]->direc[l]->direc[m]->output_link); //찾은 출력링크 번호를 리턴해줌

}

void n_nary_tree::delete_one(char ip_address[])
{	//search_output_link방식으로 같은 주소를 찾은 다음 지운다
	
	char tmp[20]; //임시로 IP주소를 받아둠
	char *tmp_ptr0; //첫번째 숫자열
	char *tmp_ptr1; //두번째 숫자열
	char *tmp_ptr2; //세번째 숫자열
	char *tmp_ptr3; //네번째 숫자열

	strcpy(tmp,ip_address);
	tmp_ptr0 = tmp;
	tmp_ptr1 = strchr(tmp,'.'); //ip_address에서 '.'을 찾음
	*tmp_ptr1 = NULL; //'.'을 null로 바꿈 
	++tmp_ptr1; //null 다음을 가르킴
	tmp_ptr2 = strchr(tmp_ptr1,'.'); //위와 같은 방법
	*tmp_ptr2 = NULL;
	++tmp_ptr2;
	tmp_ptr3 = strchr(tmp_ptr2,'.'); //위와 같은 방법
	*tmp_ptr3 = NULL;
	++tmp_ptr3;

	int k,ks; //top node 상수
	int j,js; //2번째 node 상수
	int l,ls; //3번째 node 상수
	int m,ms; //4번째 node 상수
	
	for(ks=0; ks<10 && top[ks]!=NULL; ks++); //NULL이 아닐때까지의 탑노드의 갯수를 찾음
	for(k=0; k<ks && strcmp(top[k]->data,tmp_ptr0)!=0; k++); //입력된 ip와 같을때까지 비교
	if(k==ks) 
	{	//같은 ip가 존재하지 않음
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"I can't delete IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return;
	}
	for(js=0; js<10 && top[k]->direc[js]!=NULL; js++); //NULL이 아닐때까지의 노드의 갯수를 찾음
	for(j=0; j<js && strcmp(top[k]->direc[j]->data,tmp_ptr1)!=0; j++); //입력된 ip와 같을때까지 비교
	if(j==js) 
	{	//같은 ip가 존재하지 않음
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"I can't delete IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return;
	}
	for(ls=0; ls<10 && top[k]->direc[j]->direc[ls]!=NULL; ls++); //NULL이 아닐때까지의 노드의 갯수를 찾음
	for(l=0; l<ls && strcmp(top[k]->direc[j]->direc[l]->data,tmp_ptr2)!=0; l++); //입력된 ip와 같을때까지 비교
	if(l==ls) 
	{	//같은 ip가 존재하지 않음
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"I can't delete IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return;
	}
	for(ms=0; ms<10 && top[k]->direc[j]->direc[l]->direc[ms]!=NULL; ms++); //NULL이 아닐때까지의 노드의 갯수를 찾음
	for(m=0; m<ms && strcmp(top[k]->direc[j]->direc[l]->direc[m]->data,tmp_ptr3)!=0; m++); //입력된 ip와 같을때까지 비교
	if(m==ms) 
	{	//같은 ip가 존재하지 않음
		cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"I can't delete IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return;
	}
	
	if(k!=ks && j!=js && l!=ls && m!=ms)
	{
		int i;
		//top[k]->direc[j]->direc[l]->direc[m]가 입력된 IP의 라우팅 테이블 주소
		delete top[k]->direc[j]->direc[l]->direc[m];
		//4번째 노드를 지움
		for(; m<ms; m++)
		{	//지워진 노드뒤에 있는 노드들을 앞으로 당겨줌
			top[k]->direc[j]->direc[l]->direc[m] = top[k]->direc[j]->direc[l]->direc[m+1];
		}
		delete top[k]->direc[j]->direc[l]->direc[ms];
		top[k]->direc[j]->direc[l]->direc[ms]=NULL;
		//앞으로 당겨지고 마지막 남은 노드를 지움

		for(i=0; i<10 && top[k]->direc[j]->direc[l]->direc[i]==NULL; i++);
		//3번째 노드가 비었는지 확인
		if(i==10)
		{	//비었을때
			delete top[k]->direc[j]->direc[l];
			//3번째 노드를 지움
			for(; l<ls; l++)
			{	//지워진 노드뒤에 있는 노드들을 앞으로 당겨줌
				top[k]->direc[j]->direc[l] = top[k]->direc[j]->direc[l+1];
			}
			delete top[k]->direc[j]->direc[ls];
			top[k]->direc[j]->direc[ls]=NULL;
			//앞으로 당겨지고 마지막 남은 노드를 지움

			for(i=0; i<10 && top[k]->direc[j]->direc[i]==NULL; i++);
			//2번째 노드가 비었는지 확인
			if(i==10)
			{	//비었을때
				delete top[k]->direc[j];
				//2번째 노드를 지움
				for(; j<js; j++)
				{	//지워진 노드뒤에 있는 노드들을 앞으로 당겨줌
					top[k]->direc[j] = top[k]->direc[j+1];
				}
				delete top[k]->direc[js];
				top[k]->direc[js]=NULL;
				//앞으로 당겨지고 마지막 남은 노드를 지움

				for(i=0; i<10 && top[k]->direc[i]==NULL; i++); 
				//첫번째 노드가 비었는지 확인
				if(i==10)
				{	//비었을때
					delete top[k];
					for(; k<ks; k++)
					{	//지워진 노드뒤에 있는 노드들을 앞으로 당겨줌
						top[k]= top[k+1];
					}
					delete top[ks];
					top[ks]=NULL;
					//앞으로 당겨지고 마지막 남은 노드를 지움
				}
			}
		}	//더이상 비는게 없으면 거기까지만 지우고 끝냄
	cout<<"━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"Delete IP Address : "<<ip_address<<endl;
	}
		
}

void n_nary_tree::delete_all(void)
{
	int tn_0; //top(1번째) node의 갯수
	int tn_1; //for문을 돌릴때 필요한 상수
	int nn1_0; //2번째 node의 갯수
	int nn1_1; //for문을 돌릴때 필요한 상수
	int nn2_0; //3번째 node의 갯수
	int nn2_1; //for문을 돌릴때 필요한 상수
	int nn3_0; //4번째 node의 갯수
	int nn3_1; //for문을 돌릴때 필요한 상수

	cout<<"┏━━━━━━━━━━━━━━━━━━━┓"<<endl;
	cout<<"┃       Delete All Routing table       ┃"<<endl;
	cout<<"┗━━━━━━━━━━━━━━━━━━━┛"<<endl;

	for(tn_0 =0; tn_0<10 && top[tn_0]!=NULL; tn_0++); 
	//NULL이 아닐때까지의 탑노드의 갯수를 찾음
	for(tn_1 =0; tn_1<tn_0; tn_1++)
	{
		for(nn1_0 =0; nn1_0<10 && top[tn_1]->direc[nn1_0]!=NULL; nn1_0++); 
		//NULL이 아닐때까지의 노드의 갯수를 찾음
		for(nn1_1 =0; nn1_1<nn1_0; nn1_1++)
		{
			for(nn2_0 =0; nn2_0<10 && top[tn_1]->direc[nn1_1]->direc[nn2_0]!=NULL; nn2_0++); 
			//NULL이 아닐때까지의 노드의 갯수를 찾음
			for(nn2_1 =0; nn2_1<nn2_0; nn2_1++) 
			{
				for(nn3_0 =0; nn3_0<10 && top[tn_1]->direc[nn1_1]->direc[nn2_1]->direc[nn3_0]!=NULL; nn3_0++); 
				//NULL이 아닐때까지의 노드의 갯수를 찾음
				for(nn3_1 =0; nn3_1<nn3_0; nn3_1++) 
				{
					delete top[tn_1]->direc[nn1_1]->direc[nn2_1]->direc[nn3_1]; //4번째 노드를 전부 지움
				}
				delete top[tn_1]->direc[nn1_1]->direc[nn2_1]; //3번째 노드를 전부 지움
			}
			delete top[tn_1]->direc[nn1_1]; //2번째 노드를 전부 지움
		}
		delete top[tn_1]; //1번째 노드를 전부 지움
	}
	for(int i=0; i<11; i++)
	{	//다 지웠으니 초기화
		top[i]=NULL;
	}
}

void n_nary_tree::print(void)
{
	int tn_0; //top(1번째) node의 갯수
	int tn_1; //for문을 돌릴때 필요한 상수
	int nn1_0; //2번째 node의 갯수
	int nn1_1; //for문을 돌릴때 필요한 상수
	int nn2_0; //3번째 node의 갯수
	int nn2_1; //for문을 돌릴때 필요한 상수
	int nn3_0; //4번째 node의 갯수
	int nn3_1; //for문을 돌릴때 필요한 상수

	cout<<"┏━━━━━━━━━━━━━━━━━━━┓"<<endl;
	cout<<"┃           Routing  table             ┃"<<endl;
	cout<<"┗━━━━━━━━━━━━━━━━━━━┛"<<endl;
	
	if(top[0]!=NULL)
	{
		for(tn_0 =0; tn_0<10 && top[tn_0]!=NULL; tn_0++); 
		//NULL이 아닐때까지의 탑노드의 갯수를 찾음
		for(tn_1 =0; tn_1<tn_0; tn_1++)
		{
			for(nn1_0 =0; nn1_0<10 && top[tn_1]->direc[nn1_0]!=NULL; nn1_0++); 
			//NULL이 아닐때까지의 노드의 갯수를 찾음
			for(nn1_1 =0; nn1_1<nn1_0; nn1_1++)
			{
				for(nn2_0 =0; nn2_0<10 && top[tn_1]->direc[nn1_1]->direc[nn2_0]!=NULL; nn2_0++); 
				//NULL이 아닐때까지의 노드의 갯수를 찾음
				for(nn2_1 =0; nn2_1<nn2_0; nn2_1++) 
				{
					for(nn3_0 =0; nn3_0<10 && top[tn_1]->direc[nn1_1]->direc[nn2_1]->direc[nn3_0]!=NULL; nn3_0++); 
					//NULL이 아닐때까지의 노드의 갯수를 찾음
					for(nn3_1 =0; nn3_1<nn3_0; nn3_1++) 
					{	//정렬되게 프린트 하기위해 간격을 일정하게 프린터 한다
						cout<<setw(3)<<top[tn_1]->data<<'.'
							<<setw(3)<<top[tn_1]->direc[nn1_1]->data<<'.'
							<<setw(3)<<top[tn_1]->direc[nn1_1]->direc[nn2_1]->data<<'.'
							<<setw(3)<<top[tn_1]->direc[nn1_1]->direc[nn2_1]->direc[nn3_1]->data<<" output_link : "
							<<setw(3)<<top[tn_1]->direc[nn1_1]->direc[nn2_1]->direc[nn3_1]->output_link<<endl;
					}
				}
			}
		}
	}
	else	//table이 비었을때 비었다고 출력
	cout<<"         Routing table is empty"<<endl;
}