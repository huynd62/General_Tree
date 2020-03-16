#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
struct node{
	int data;
	
	vector<node *> child;
	struct node *parent;
};
node* taonode(int x)
{
	node *c = new node;
	c->data = x;
	return c;	
}
void cha_con(node* cha,node* con)
{
	cha->child.push_back(con);
	con->parent = cha;
}
void incay(node *root)
{
	if(root == NULL)
	{
		return;
	}
	queue<node*> q;
	q.push(root);
	
	while (!q.empty())
	{
		int n = q.size();
		while( n> 0)
		{
			node *p = q.front();
			q.pop();
			cout<<p->data<<" ";
			for(int i= 0; i< p->child.size();i++)
			{
				q.push(p->child[i]);
			}
			n--;
		}
		cout<<endl;
	}
}
void duyetchieurong(node* root,int dich)
{
	deque<node* > a;
	a.push_back(root);
	int stt =1;
	bool c = false;
	while(!a.empty())
	{
		if(c== true)
		{
			break;
		}
		cout<<stt<<": "<<endl;
		cout<<"pop "<<a[0]->data<<endl;
		node *cha = a[0];
		a.pop_front();
		

			for(int j=0;j<cha->child.size();j++)
			{
				a.push_back(cha->child[j]);
				cout<<"push: "<<cha->child[j]->data<<" ;";
				if(cha->child[j]->data == dich)
				{
					cout<<endl;
					cout<<"Da tim ra "<<dich<<endl;;
					node* ketqua = cha->child[j];
					cout<<"duong di"<<endl;
					while(ketqua != NULL)
					{
						cout<<ketqua->data<<"-";
						ketqua = ketqua->parent;
					}
					c = true;
					break;
				}
			}
			stt++;
			cout<<endl;
		
	}
	cout<<endl;
	if(c != true)
	{
		cout<<"khong co nut do tren cay";
	}
}
void duyetchieusau(node* root,int dich)
{
	
		bool l = false;
		node* current = root;

		vector<node*> open;
		open.push_back(current);

		while(!open.empty())
		{
			cout<<open[open.size()-1]->data<<"-";			
			if(open[open.size()-1]->data == dich)
			{
				cout<<endl;
				cout<<"Da tim thay diem "<<dich<<endl;
				node* ketqua = open[open.size()-1];
				cout<<"duong di"<<endl;
				while(ketqua != NULL)
				{
					cout<<ketqua->data<<"-";
					ketqua = ketqua->parent;
				
				} 
				l = true;
				return;
			}
			vector<node*> con= open[open.size()-1]->child;

			open.pop_back();
			if(con.size() >0)
			{
				for(int i = con.size()-1;i>=0;i--)
				{

							open.push_back(con[i]);

				}
			}
			
		}
		if(l == false)
		{
			cout<<endl;
			cout<<"khong co nut do tren cay";
		}
	
			
}

int main()
{
	int s;
	cout<<"moi nhap so phan tu cua s:";
	cin>>s;
	if(s == 0)
	{
		cout<<"Cay rong";
		return 0;
	}
	if(s == 1)
	{
		char v;
		cout<<"Cay co 1 node"<<endl;
		cout<<"moi ban nhap node thu 1:"<<endl;
		cin>>v;
		cout<<"Cay cua ban l�:"<<endl;
		cout<<v;
		return 0;
	}
	cout<<"Moi ban nhap nut goc"<<endl;
	node *root = new node;
	cin>>root->data;
	root->parent = NULL;
	deque<node*> a;
	a.push_back(root);
	while(!a.empty())
	{
			int i =0;
			int d;
			cout<<"Node"<<a[i]->data<<" co con khong?"<<endl;
			cout<<"1.co"<<endl;
			cout<<"2.khong"<<endl;
			cin>>d;
			while( d == 1)
			{
				node *t = new node;
				cout<<"Moi nhap gia tri node con :"<<endl;
				cin>>t->data;
				cha_con(a[i],t);
				a.push_back(t);
				cout<<endl;
				cout<<"Nhap them nut con ?(1:yes;2:no)"<<endl;
				cin>>d;
				
			}
			a.pop_front();
				
	}
	cout<<"Bieu dien cay"<<endl;
	incay(root);
	cout<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<"Tim kiem theo chieu rong:"<<endl;
	int f;
	cout<<"Ban muon tim kiem diem nao ?"<<endl;
	cin>>f;
	duyetchieurong(root,f);
	cout<<endl;
	cout<<endl;
	cout<<"Tim kiem theo chieu sau:"<<endl;
	duyetchieusau(root,f);

	return 0;
}

