#include"n_nary_tree.h"

void n_nary_tree::enter_one(char ip_address[], int output_link)
{
	int tn; //top number
	int i;
	char tmp[10]; //�ӽ÷� IP�ּҸ� �޾Ƶ�
	
	for(i=0; ip_address[i]!='.'; i++)
	{	//ó�� '.'�� ���ö����� IP�ּҸ� �ӽú����� ����
		tmp[i]=ip_address[i];
	}
	tmp[i]=NULL; //'.'�� NULL���� ��ȯ

	for(tn=0; tn<10 && top[tn]!=NULL && strcmp(top[tn]->data,tmp)!=0; tn++);
		//���� IP�ּҸ� ���� top node�� ã��

	if(tn==10){ //10���� �Ѵµ��� �������� ������ �� �� �����Ƿ� �� �߰���ų�� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"Tree's top node is full!!"<<endl;
		return;
	}

	if(top[tn]==NULL){ //���� IP�� ���� top node�� ������ ���� �����
		top[tn] = new node;
		strcpy(top[tn]->data,tmp);
	}

	enter(top[tn], &ip_address[i+1], output_link);
}

void n_nary_tree::enter(node *direc, char *adrs, int output_link)
{
	int dn; //direction number
	int i;
	char tmp[10]; //�ӽ÷� IP�ּҸ� �޾Ƶ�
	
	if(adrs[0]==NULL)
	{	//�ּҸ� �� �Է� ��Ű�� ���� ������ node�� ��¸�ũ ��ȣ�� �Է� ��Ų��
		direc->output_link=output_link;
		return;
	}

	for(i=0; adrs[i]!='.' && adrs[i]!=NULL; i++)
	{	//'.'�� �����ų� NULL�� ������ IP�ּҸ� �ӽú����� ����
		tmp[i]=adrs[i];
	}
	tmp[i]=NULL; //'.'�� NULL���� ��ȯ

	for(dn=0; dn<10 && direc->direc[dn]!=NULL && strcmp(direc->direc[dn]->data,tmp)!=0; dn++);
		//���� IP�ּҸ� ���� node�� ã��

	if(dn==10){ //10���� �Ѵµ��� �������� ������ �� �� �����Ƿ� �� �߰���ų�� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"Tree's node is full!!"<<endl;
		return;
	}

	if(direc->direc[dn]==NULL){ //���� IP�� ���� node�� ������ ���� �����
		direc->direc[dn] = new node;
		strcpy(direc->direc[dn]->data,tmp);		
	}
	enter(direc->direc[dn], adrs+i+1, output_link); 
	//������ IP�ּұ��� �� �Է� ��ų�� ���� �ڱ��ڽ��� ȣ��

}

char *strchr(char *string_ptr, char find) 
{  //���� �ð��� ��� �Լ�, ���ϴ� ĳ������ ��ġ�� ã��.
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
	char tmp[20]; //�ӽ÷� IP�ּҸ� �޾Ƶ�
	char *tmp_ptr0; //ù��° ���ڿ�
	char *tmp_ptr1; //�ι�° ���ڿ�
	char *tmp_ptr2; //����° ���ڿ�
	char *tmp_ptr3; //�׹�° ���ڿ�

	strcpy(tmp,ip_address);
	tmp_ptr0 = tmp;
	tmp_ptr1 = strchr(tmp,'.'); //ip_address���� '.'�� ã��
	*tmp_ptr1 = NULL; //'.'�� null�� �ٲ� 
	++tmp_ptr1; //null ������ ����Ŵ
	tmp_ptr2 = strchr(tmp_ptr1,'.'); //���� ���� ���
	*tmp_ptr2 = NULL;
	++tmp_ptr2;
	tmp_ptr3 = strchr(tmp_ptr2,'.'); //���� ���� ���
	*tmp_ptr3 = NULL;
	++tmp_ptr3;

	int k,ks; //top node ���
	int j,js; //2��° node ���
	int l,ls; //3��° node ���
	int m,ms; //4��° node ���

	for(ks=0; ks<10 && top[ks]!=NULL; ks++); //NULL�� �ƴҶ������� ž����� ������ ã��
	for(k=0; k<ks && strcmp(top[k]->data,tmp_ptr0)!=0; k++); //�Էµ� ip�� ���������� ��
	if(k==ks) 
	{	//���� ip�� �������� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"I can't search IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return (0);
	}
	for(js=0; js<10 && top[k]->direc[js]!=NULL; js++); //NULL�� �ƴҶ������� ����� ������ ã��
	for(j=0; j<js && strcmp(top[k]->direc[j]->data,tmp_ptr1)!=0; j++); //�Էµ� ip�� ���������� ��
	if(j==js) 
	{	//���� ip�� �������� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"I can't search IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return (0);
	}
	for(ls=0; ls<10 && top[k]->direc[j]->direc[ls]!=NULL; ls++); //NULL�� �ƴҶ������� ����� ������ ã��
	for(l=0; l<ls && strcmp(top[k]->direc[j]->direc[l]->data,tmp_ptr2)!=0; l++); //�Էµ� ip�� ���������� ��
	if(l==ls) 
	{	//���� ip�� �������� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"I can't search IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return (0);
	}
	for(ms=0; ms<10 && top[k]->direc[j]->direc[l]->direc[ms]!=NULL; ms++); //NULL�� �ƴҶ������� ����� ������ ã��
	for(m=0; m<ms && strcmp(top[k]->direc[j]->direc[l]->direc[m]->data,tmp_ptr3)!=0; m++); //�Էµ� ip�� ���������� ��
	if(m==ms) 
	{	//���� ip�� �������� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"I can't search IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return (0);
	}

	cout<<"������������������������������������������"<<endl;
	cout<<"We found IP Address : "<<ip_address<<endl;
	return(top[k]->direc[j]->direc[l]->direc[m]->output_link); //ã�� ��¸�ũ ��ȣ�� ��������

}

void n_nary_tree::delete_one(char ip_address[])
{	//search_output_link������� ���� �ּҸ� ã�� ���� �����
	
	char tmp[20]; //�ӽ÷� IP�ּҸ� �޾Ƶ�
	char *tmp_ptr0; //ù��° ���ڿ�
	char *tmp_ptr1; //�ι�° ���ڿ�
	char *tmp_ptr2; //����° ���ڿ�
	char *tmp_ptr3; //�׹�° ���ڿ�

	strcpy(tmp,ip_address);
	tmp_ptr0 = tmp;
	tmp_ptr1 = strchr(tmp,'.'); //ip_address���� '.'�� ã��
	*tmp_ptr1 = NULL; //'.'�� null�� �ٲ� 
	++tmp_ptr1; //null ������ ����Ŵ
	tmp_ptr2 = strchr(tmp_ptr1,'.'); //���� ���� ���
	*tmp_ptr2 = NULL;
	++tmp_ptr2;
	tmp_ptr3 = strchr(tmp_ptr2,'.'); //���� ���� ���
	*tmp_ptr3 = NULL;
	++tmp_ptr3;

	int k,ks; //top node ���
	int j,js; //2��° node ���
	int l,ls; //3��° node ���
	int m,ms; //4��° node ���
	
	for(ks=0; ks<10 && top[ks]!=NULL; ks++); //NULL�� �ƴҶ������� ž����� ������ ã��
	for(k=0; k<ks && strcmp(top[k]->data,tmp_ptr0)!=0; k++); //�Էµ� ip�� ���������� ��
	if(k==ks) 
	{	//���� ip�� �������� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"I can't delete IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return;
	}
	for(js=0; js<10 && top[k]->direc[js]!=NULL; js++); //NULL�� �ƴҶ������� ����� ������ ã��
	for(j=0; j<js && strcmp(top[k]->direc[j]->data,tmp_ptr1)!=0; j++); //�Էµ� ip�� ���������� ��
	if(j==js) 
	{	//���� ip�� �������� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"I can't delete IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return;
	}
	for(ls=0; ls<10 && top[k]->direc[j]->direc[ls]!=NULL; ls++); //NULL�� �ƴҶ������� ����� ������ ã��
	for(l=0; l<ls && strcmp(top[k]->direc[j]->direc[l]->data,tmp_ptr2)!=0; l++); //�Էµ� ip�� ���������� ��
	if(l==ls) 
	{	//���� ip�� �������� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"I can't delete IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return;
	}
	for(ms=0; ms<10 && top[k]->direc[j]->direc[l]->direc[ms]!=NULL; ms++); //NULL�� �ƴҶ������� ����� ������ ã��
	for(m=0; m<ms && strcmp(top[k]->direc[j]->direc[l]->direc[m]->data,tmp_ptr3)!=0; m++); //�Էµ� ip�� ���������� ��
	if(m==ms) 
	{	//���� ip�� �������� ����
		cout<<"������������������������������������������"<<endl;
		cout<<"I can't delete IP_address"<<endl;
		cout<<"IP : "<<ip_address<<" does not exist!"<<endl;
		return;
	}
	
	if(k!=ks && j!=js && l!=ls && m!=ms)
	{
		int i;
		//top[k]->direc[j]->direc[l]->direc[m]�� �Էµ� IP�� ����� ���̺� �ּ�
		delete top[k]->direc[j]->direc[l]->direc[m];
		//4��° ��带 ����
		for(; m<ms; m++)
		{	//������ ���ڿ� �ִ� ������ ������ �����
			top[k]->direc[j]->direc[l]->direc[m] = top[k]->direc[j]->direc[l]->direc[m+1];
		}
		delete top[k]->direc[j]->direc[l]->direc[ms];
		top[k]->direc[j]->direc[l]->direc[ms]=NULL;
		//������ ������� ������ ���� ��带 ����

		for(i=0; i<10 && top[k]->direc[j]->direc[l]->direc[i]==NULL; i++);
		//3��° ��尡 ������� Ȯ��
		if(i==10)
		{	//�������
			delete top[k]->direc[j]->direc[l];
			//3��° ��带 ����
			for(; l<ls; l++)
			{	//������ ���ڿ� �ִ� ������ ������ �����
				top[k]->direc[j]->direc[l] = top[k]->direc[j]->direc[l+1];
			}
			delete top[k]->direc[j]->direc[ls];
			top[k]->direc[j]->direc[ls]=NULL;
			//������ ������� ������ ���� ��带 ����

			for(i=0; i<10 && top[k]->direc[j]->direc[i]==NULL; i++);
			//2��° ��尡 ������� Ȯ��
			if(i==10)
			{	//�������
				delete top[k]->direc[j];
				//2��° ��带 ����
				for(; j<js; j++)
				{	//������ ���ڿ� �ִ� ������ ������ �����
					top[k]->direc[j] = top[k]->direc[j+1];
				}
				delete top[k]->direc[js];
				top[k]->direc[js]=NULL;
				//������ ������� ������ ���� ��带 ����

				for(i=0; i<10 && top[k]->direc[i]==NULL; i++); 
				//ù��° ��尡 ������� Ȯ��
				if(i==10)
				{	//�������
					delete top[k];
					for(; k<ks; k++)
					{	//������ ���ڿ� �ִ� ������ ������ �����
						top[k]= top[k+1];
					}
					delete top[ks];
					top[ks]=NULL;
					//������ ������� ������ ���� ��带 ����
				}
			}
		}	//���̻� ��°� ������ �ű������ ����� ����
	cout<<"������������������������������������������"<<endl;
	cout<<"Delete IP Address : "<<ip_address<<endl;
	}
		
}

void n_nary_tree::delete_all(void)
{
	int tn_0; //top(1��°) node�� ����
	int tn_1; //for���� ������ �ʿ��� ���
	int nn1_0; //2��° node�� ����
	int nn1_1; //for���� ������ �ʿ��� ���
	int nn2_0; //3��° node�� ����
	int nn2_1; //for���� ������ �ʿ��� ���
	int nn3_0; //4��° node�� ����
	int nn3_1; //for���� ������ �ʿ��� ���

	cout<<"������������������������������������������"<<endl;
	cout<<"��       Delete All Routing table       ��"<<endl;
	cout<<"������������������������������������������"<<endl;

	for(tn_0 =0; tn_0<10 && top[tn_0]!=NULL; tn_0++); 
	//NULL�� �ƴҶ������� ž����� ������ ã��
	for(tn_1 =0; tn_1<tn_0; tn_1++)
	{
		for(nn1_0 =0; nn1_0<10 && top[tn_1]->direc[nn1_0]!=NULL; nn1_0++); 
		//NULL�� �ƴҶ������� ����� ������ ã��
		for(nn1_1 =0; nn1_1<nn1_0; nn1_1++)
		{
			for(nn2_0 =0; nn2_0<10 && top[tn_1]->direc[nn1_1]->direc[nn2_0]!=NULL; nn2_0++); 
			//NULL�� �ƴҶ������� ����� ������ ã��
			for(nn2_1 =0; nn2_1<nn2_0; nn2_1++) 
			{
				for(nn3_0 =0; nn3_0<10 && top[tn_1]->direc[nn1_1]->direc[nn2_1]->direc[nn3_0]!=NULL; nn3_0++); 
				//NULL�� �ƴҶ������� ����� ������ ã��
				for(nn3_1 =0; nn3_1<nn3_0; nn3_1++) 
				{
					delete top[tn_1]->direc[nn1_1]->direc[nn2_1]->direc[nn3_1]; //4��° ��带 ���� ����
				}
				delete top[tn_1]->direc[nn1_1]->direc[nn2_1]; //3��° ��带 ���� ����
			}
			delete top[tn_1]->direc[nn1_1]; //2��° ��带 ���� ����
		}
		delete top[tn_1]; //1��° ��带 ���� ����
	}
	for(int i=0; i<11; i++)
	{	//�� �������� �ʱ�ȭ
		top[i]=NULL;
	}
}

void n_nary_tree::print(void)
{
	int tn_0; //top(1��°) node�� ����
	int tn_1; //for���� ������ �ʿ��� ���
	int nn1_0; //2��° node�� ����
	int nn1_1; //for���� ������ �ʿ��� ���
	int nn2_0; //3��° node�� ����
	int nn2_1; //for���� ������ �ʿ��� ���
	int nn3_0; //4��° node�� ����
	int nn3_1; //for���� ������ �ʿ��� ���

	cout<<"������������������������������������������"<<endl;
	cout<<"��           Routing  table             ��"<<endl;
	cout<<"������������������������������������������"<<endl;
	
	if(top[0]!=NULL)
	{
		for(tn_0 =0; tn_0<10 && top[tn_0]!=NULL; tn_0++); 
		//NULL�� �ƴҶ������� ž����� ������ ã��
		for(tn_1 =0; tn_1<tn_0; tn_1++)
		{
			for(nn1_0 =0; nn1_0<10 && top[tn_1]->direc[nn1_0]!=NULL; nn1_0++); 
			//NULL�� �ƴҶ������� ����� ������ ã��
			for(nn1_1 =0; nn1_1<nn1_0; nn1_1++)
			{
				for(nn2_0 =0; nn2_0<10 && top[tn_1]->direc[nn1_1]->direc[nn2_0]!=NULL; nn2_0++); 
				//NULL�� �ƴҶ������� ����� ������ ã��
				for(nn2_1 =0; nn2_1<nn2_0; nn2_1++) 
				{
					for(nn3_0 =0; nn3_0<10 && top[tn_1]->direc[nn1_1]->direc[nn2_1]->direc[nn3_0]!=NULL; nn3_0++); 
					//NULL�� �ƴҶ������� ����� ������ ã��
					for(nn3_1 =0; nn3_1<nn3_0; nn3_1++) 
					{	//���ĵǰ� ����Ʈ �ϱ����� ������ �����ϰ� ������ �Ѵ�
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
	else	//table�� ������� ����ٰ� ���
	cout<<"         Routing table is empty"<<endl;
}