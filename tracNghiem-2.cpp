 #include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include<windows.h>
#include<time.h>
#include <conio.h>
using namespace std;
//cau truc cau hoi
struct CAUHOI
{
	
	string  stt, cauHoi, cauA, cauB, cauC, cauD, dapAn;
};

struct NODE
{
	CAUHOI data;
	NODE *link;
};

struct LIST
{
	NODE *first, *last;
	int soLuong;
};
//cau truc ramdom 
struct RAND_NODE
{
	int a;
	RAND_NODE *link;
};
struct RAND_LIST
{
	RAND_NODE *first, *last;
};
//cau truc dang ky
struct DANGKY
{
	string tk;
	string mk;
	
};
struct NODE_DK 
{
	DANGKY data;
	NODE_DK *link;
};
struct LIST_DK
{
	NODE_DK *first,*last;
};
void Init(LIST &l);
NODE *getNode(CAUHOI x);
void addLastCauHoi(LIST &l, CAUHOI x);
void InitRand(RAND_LIST &l);
void capNhatCauHoi(LIST &l, int maCauHoi);
RAND_NODE *getNodeRand(int a);
void addLastRand(RAND_LIST &l, int a);
void createSTT(RAND_LIST &l, LIST l1, int soLuong);
bool kiemTraTrung(RAND_LIST l, int so);
void themVaoList(LIST &l);//doc file them cau hoi vao list
void xuatCauHoi(LIST l,int &y);
void themCauHoiVaoFile(LIST &l);
void Thi(LIST l);
void luat();
int chuyenDoi(string s);// chuyen stt kieu string sang int
NODE* search(LIST l,int so);
void xoaDau(LIST &l);
void xoaCuoi(LIST &l);
void xoaAW(LIST &l, int stt);
void capNhatFileCauHoi(LIST l);// cap nhat cau hoi sau khi xoa vao file
void capNhatSTTSauXoa(LIST &l);//cap nhat stt sau khi xoa
void loading();
void gotoxy(int x,int y);
bool kiemTraTKAdmin(string tk, string mk);
void chucNangAdmin(LIST &l);
void doiMK();//doi mat khau tai khoan admin
void endProgram();
void passSao(char s[]);//tao * khi nha password
void deleteALL(LIST &l);
void menu();
void InitDK(LIST_DK &l);
NODE_DK *getNodeDK(DANGKY x);
void addLastDK(LIST_DK &l,DANGKY x);
void docFile(LIST_DK &l);
int tim(LIST_DK &l,DANGKY x);
void dangKyTK(LIST_DK &l);
int dangNhap(LIST_DK l,string tk, string mk);
void chucNangThiSinh();
void thisinh();
void doiMKThiSinh(LIST_DK &l);
NODE_DK *searchTK(LIST_DK &l, string tk);
int main(int argc, char *argv[])
{
	LIST l;
	Init(l);
	LIST_DK l1;
	InitDK(l1);
	int y;
	char a='a';
	char MK[50];
	string tk,mk;
	themVaoList(l);
	while(a!=27)
	{
		system("cls");
		printf("              0      0       0   000000   0        0  	    000000    000000    0         0   000000    \n");
		printf("               0    0 0     0    00       0        0       0         0      0   0 0     0 0   00        \n");
		printf("                0   0  0   0     00000    0        0       0         0      0   0  0   0  0   000000    \n");
		printf("                 0 0    0 0      00       0        0       0         0      0   0   0 0   0   00        \n");
		printf("                  0      0       000000   000000   000000   000000    000000    0    0    0   000000    \n");
		
		gotoxy(40,8);
		printf("CHU DE : Thi Trac Nghiem Tieng Anh");
		gotoxy(40,12);
		printf("ESC. Thoat");
		gotoxy(40,13);
		printf("F1. Thi sinh");
		gotoxy(40,14);
		printf("F2. Quyen Admin");
		gotoxy(40,15);
		a=getch();	
		switch(a)
		{
			case 27:
				
				endProgram();
				deleteALL(l);
				break;
			case 59:
				thisinh();
				break;
			case 60:
				system("cls");
				gotoxy(25,3);
				printf("Vui long dang nhap tai khoan admin de su dung");
				gotoxy(30,5);
				printf("Tai khoan: ");
				gotoxy(41,5);
				cin>>tk;
				gotoxy(30,7);
				fflush(stdin);
				printf("Mat khau: ");
				gotoxy(40,7);
				passSao(MK);
				mk=MK;
				if(kiemTraTKAdmin(tk,mk))
					chucNangAdmin(l);
				else
				{
					gotoxy(30,9);
					printf("Tai khoan chua dung");
					Sleep(3000);
				}
				break;
			default:
				break;
		}
	}
	gotoxy(34,15);
	return 0;
}

void Init(LIST &l)
{
	l.first=l.last=NULL;
	l.soLuong=0;
}

NODE *getNode(CAUHOI x)
{
	NODE *p=new NODE;
	if(p==NULL)
		return NULL;
	p->data=x;
	p->link=NULL;
	return p;
}
void addLastCauHoi(LIST &l, CAUHOI x)
{
	NODE *p=getNode(x);
	if(p==NULL)
		return;
	if(l.first==NULL){
		l.first=l.last=p;
		l.soLuong++;
	}	
	else
	{
		l.last->link=p;
		l.last=p;
		l.soLuong++;
	}
}
//Doc file luu vao list
void themVaoList(LIST &l)
{
	ifstream fp;
	fp.open("cauhoi.txt",ios_base::in);
	while(!fp.eof())
	{
		CAUHOI x;
		getline(fp,x.stt);
		getline(fp,x.cauHoi);
		getline(fp,x.cauA);
		getline(fp,x.cauB); 
		getline(fp,x.cauC);
		getline(fp,x.cauD);
		getline(fp,x.dapAn);
		addLastCauHoi(l,x);
	}
	fp.close();
}
void xuatCauHoi(LIST l, int &y)
{
	if(l.first==NULL)
		return;
	NODE *p=l.first;
	while(p!=NULL)
	{
		gotoxy(20,y);
		y++;
		cout<<"Cau "<<p->data.stt<<": "<<p->data.cauHoi<<endl;
		p=p->link;
	}
}
void Thi(LIST l)
{
	NODE *q;
	LIST l1;
	RAND_LIST l2;
	InitRand(l2);
	Init(l1);
	int a=0, STT=1;
	int soLuong;
	clock_t t1,t2;
	//nhap so luong cau hoi
	while(true)
	{
		system("cls");
        gotoxy(40,4);
        printf("+------------------------------ +");
		gotoxy(40,5);
		printf("|ban chon goi cau hoi 10 hay 20 |");
		gotoxy(40,6);
        printf("+------------------------------ +\n");
       	gotoxy(49,7);
                    printf("+========+");
        gotoxy(53,8);
	            	scanf("%d",&soLuong);
        gotoxy(49,9);
                    printf("+========+");
		if(soLuong!=10&&soLuong!=20){
			printf("Nhap sai,moi chon lai goi cau hoi");
		}		
		else break;
	}
	loading();
	createSTT(l2,l,soLuong);//tao ngau nhien list stt
	RAND_NODE *p=l2.first;
	t1=clock();
	while(p!=NULL)
	{
		
		q = search(l,p->a);//tim kiem dia chi cua stt tuong ung
    	system("cls");
        gotoxy(25,1);
		printf("|---------------------------------------|");
		gotoxy(25,2);
		printf("| Nhap  a, b, c, d  de chon dap an      |");
		gotoxy(25,3);
		printf("|---------------------------------------|");
		gotoxy(25,6);
		cout<<"Cau "<<STT<<" :"<<q->data.cauHoi<<endl;
		gotoxy(25,9);
		cout<<q->data.cauA<<endl;
		gotoxy(25,12);
		cout<<q->data.cauB<<endl;
		gotoxy(25,15);
		cout<<q->data.cauC<<endl;
		gotoxy(25,18);
		cout<<q->data.cauD<<endl;
		printf("       ===========================================================================================================");
	
		string s;//kiem tra dap an nhap vao cua thi sinh
		char s1[5];
		int y=20;
		while(true)
		{
		gotoxy(25,y);
			fflush(stdin);
			s=getch();
			strcpy(s1,s.c_str());
			if(stricmp(s1,"a")!=0 && stricmp(s1,"b")!=0 && stricmp(s1,"c")!=0 && stricmp(s1,"d")!=0)
			{
				y++;
				gotoxy(25,y);
				printf("Nhap lai\n");
			}	
			else
				break;	
		}
		  //check dap an
		char s3[q->data.dapAn.size()];
		strcpy(s3,q->data.dapAn.c_str());//copy dap an vao s3
		if(stricmp(s1,s3)==0)//dap an dung
			a++;
  	        STT++;//tang stt cau hoi
            p=p->link;
	}t2=clock();//ket thuc dem thoi gian
	system("cls");
	double t=t2-t1;//tinh thoi gian thi
	float diem;
	if(soLuong==10)
	diem=10.0*a;
	else if(soLuong==20)
	diem =5*a;
	gotoxy(40,15);
	printf("+--------------------------------------------+");
	gotoxy(40,16);
	printf("|            Ban da lam dung :               |");
	gotoxy(40,17);
	printf("|%d cau                                       |",a);
	gotoxy(40,18);
	printf("|Diem : %.2f diem                           |",diem);
	gotoxy(40,19);
	printf("|thoi gian la %.1lf s                         |",t/1000);
	if(diem>=50){
		gotoxy(40,20);
	printf("|thanh tich :dat                               |");
	}
    else{
	gotoxy(40,20);
	printf("|thanh tich :khong dat                       |");
	}
	gotoxy(40,21);
	printf("+--------------------------------------------+");
	Sleep(3000);
}
//them 1 cau hoi vao cuoi file
void themCauHoiVaoFile(LIST &l)
{
	system("cls");
	CAUHOI x;
	char temp[20];
	sprintf(temp,"%d",l.soLuong+1);//tao stt cho cau moi
	x.stt=temp;
	//nhap cau hoi
	gotoxy(10,4);
	printf("Nhap cau hoi: ");
	fflush(stdin);
	getline(cin,x.cauHoi);
	gotoxy(10,6);
	printf("Nhap dap an: ");
	fflush(stdin);
	gotoxy(10,7);
	printf("a. ");
	getline(cin,x.cauA);
	fflush(stdin);
	gotoxy(10,9);
	printf("b. ");
	getline(cin,x.cauB);
	fflush(stdin);
	gotoxy(10,11);
	printf("c. ");
	getline(cin,x.cauC);
	fflush(stdin);
	gotoxy(10,13);
	printf("d. ");
	getline(cin,x.cauD);
	
	//kiem tra dap an
	char s[5];
	int y=15;
	while(true)
	{
		gotoxy(10,y++);
		printf("Dap an dung: ");
		fflush(stdin);
		gets(s);
		if(stricmp(s,"a")!=0 && stricmp(s,"b")!=0 && stricmp(s,"c")!=0 && stricmp(s,"d")!=0)
		{
			gotoxy(10,y++);
			printf("Nhap lai");
		}	
		else
			break;	
	}
	x.dapAn=s;
	addLastCauHoi(l,x);
	ofstream fp;
	fp.open("cauhoi.txt",ios_base::app);
	fp<<"\n";
	fp<<x.stt<<endl;
	fp<<x.cauHoi<<endl;
	fp<<"a. ";
	fp<<x.cauA<<endl;
	fp<<"b. ";
	fp<<x.cauB<<endl;
	fp<<"c. ";
	fp<<x.cauC<<endl;
	fp<<"d. ";
	fp<<x.cauD<<endl;
	fp<<x.dapAn;	
	fp.close();
}
void luat()
{
	ifstream fp;
	fp.open("luat.txt",ios_base::in);
	string s;
	int y=2;
	while(!fp.eof())
	{
		getline(fp,s);
		gotoxy(25,y++);
		cout<<s;
	}
	return;
}
void InitRand(RAND_LIST &l)
{
	l.first=l.last=NULL;
}
RAND_NODE *getNodeRand(int a)
{
	RAND_NODE *p=new RAND_NODE;
	if(p==NULL)
		return NULL;
	p->a=a;
	p->link=NULL;
	return p;
}
void addLastRand(RAND_LIST &l, int a)
{
	RAND_NODE *p=getNodeRand(a);
	if(p==NULL)
		return;
	if(l.first==NULL)
		l.first=l.last=p;
	else
	{
		l.last->link=p;
		l.last=p;
	}
}
bool kiemTraTrung(RAND_LIST l, int so)
{
	if(l.first==NULL)
		return true;
	else
	{
		RAND_NODE *p=l.first;
		while(p!=NULL)
		{
			if(p->a==so)
				return false;
			p=p->link;
		}
		
	}
	return true;
}
void createSTT(RAND_LIST &l,LIST l1, int soLuong)
{
	srand(time(NULL));
	for(int i=0;i<soLuong;i++)
	{
		int x=1+ rand()%l1.soLuong;
		if(kiemTraTrung(l,x)==false)
			i--;
		else
			addLastRand(l,x);
	}
}
NODE *search(LIST l, int so)
{
	NODE *p=l.first;	
	while(p!=NULL)
	{
		if(so==chuyenDoi(p->data.stt)){
			return p;
		}
		p=p->link;
	}
	return NULL;
}

int chuyenDoi(string s)
{
	char s1[s.size()];
	strcpy(s1,s.c_str());
	int a=atof(s1); // chuyen string thah int
	return a;
}

void xoaDau(LIST &l)
{
	NODE *p=l.first;
	l.first=p->link;
	delete p;
}
void xoaCuoi(LIST &l)
{
	NODE *p=l.first;
	while(p!=NULL)
	{
		if(p->link==l.last)
		{
			p->link=NULL;
			delete l.last;
			l.last=p;
			break;
			
		}
		p=p->link;
	}
}

void xoaAW(LIST &l, int stt)
{
	NODE *p=l.first;
	NODE *q;
	if(stt==chuyenDoi(l.first->data.stt))
	{
		xoaDau(l);
		l.soLuong--;
		return;
	}
	if(stt==chuyenDoi(l.last->data.stt))
	{
		xoaCuoi(l);
		l.soLuong--;
		return;
	}
	while(p!=NULL)
	{
		q=p;
		p=p->link;
		if(stt==chuyenDoi(p->data.stt))
		{
			q->link=p->link;
			delete p;
			l.soLuong--;
			return;
		}
	}	
}
void capNhatFileCauHoi(LIST l)
{
	ofstream fp;
	fp.open("cauhoi.txt",ios_base::trunc);
	NODE *p=l.first;
	while(p!=NULL)
	{
		fp<<p->data.stt<<endl;
		fp<<p->data.cauHoi<<endl;
		fp<<p->data.cauA<<endl;
		fp<<p->data.cauB<<endl;
		fp<<p->data.cauC<<endl;
		fp<<p->data.cauD<<endl;
		if(p!=l.last)
			fp<<p->data.dapAn<<endl;
		else
			fp<<p->data.dapAn;
		p=p->link;
	}
	fp.close();
}
void capNhatSTTSauXoa(LIST &l)
{
	NODE *p=l.first;
	for(int i=1;i<=l.soLuong;i++)
	{
		char s[5];
		itoa(i,s,10); //chuyen tu int sang string voi co so 10
		p->data.stt=s;
		p=p->link;
	}
}
void gotoxy(int x, int y)
{
  HANDLE h = NULL;  
  if(!h)
  	h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void loading()
{
	system("cls");
	gotoxy(51,12);printf( "TAI DU LIEU...");
	for( int i = 0 ; i <= 50 ; i++ ){
		gotoxy(34 + i,13);cout << char(219);
		gotoxy(55,14);cout << i * 2 << "%";
			Sleep(30);
		}
}
bool kiemTraTKAdmin(string tk, string mk)
{
	ifstream fp;
	fp.open("admin.txt",ios_base::in); //mo file dau vao
	string TK,MK;
	getline(fp,TK);
	getline(fp,MK);
	if(tk.compare(TK)==0&&mk.compare(MK)==0)
		return true;
	return false;
}
void doiMK()
{
	ifstream fp;
	string tk;
	fp.open("admin.txt",ios_base::in);//mo file lay tk, mk
	getline(fp,tk);
	fp.close();
	string mk1,mk2;
	int a=1;
	while(a!=0)
	{
		char MK1[50],MK2[50];
		system("cls");
		gotoxy(30,5);
		printf("Mat khau moi: ");
		gotoxy(44,5);
		passSao(MK1);
		mk1=MK1;
		gotoxy(30,7);
		printf("Xac nhan lai mat khau: ");
		gotoxy(52,7);
		passSao(MK2);
		mk2=MK2;
		if(mk1.compare(mk2)==0)
		{
			ofstream fp1;
			fp1.open("admin.txt",ios_base::trunc);//luu tk,mk moi vao file 
//neu tep duoc mo da ton tai dl,noi dung truoc do bi xoa,them vao noi dung moi
			fp1<<tk;
			fp1<<"\n";
			fp1<<mk1;
			MessageBox(NULL,"Doi thanh cong","Thong bao",MB_OK|MB_ICONINFORMATION);
			fp1.close();
			break;
		}
		else
		{	
			while(1)
			{
				system("cls");
				gotoxy(40,3);
		    	printf("Mat khau khong khop");
				gotoxy(40,4);
		     	printf("0. thoat");
		 		gotoxy(40,5);
		 		printf("1. Nhap lai");
		 		gotoxy(40,6);
		 		printf("Chon: ");
		 		gotoxy(46,6);
		 		cin>>a;
		 		if(a==0 || a==1)
		 			break;
			}	
		}
	}	
}
void chucNangAdmin(LIST &l)
{
	int stt,y=3;
	char a='a';
	while(a!=48)
	{
		system("cls");
		menu();
		gotoxy(40,12);
		printf("0. Thoat");
		gotoxy(40,13);
		printf("1. Xuat cau hoi");
		gotoxy(40,14);
		printf("2. Them cau hoi");
		gotoxy(40,15);
		printf("3. Xoa cau hoi");
		gotoxy(40,16);
		printf("4. Doi mat khau");
		gotoxy(40,17);
	    printf("5. Cap nhat cau hoi");
		gotoxy(40,18);
		a=getch();
		system("cls");
		switch(a)
		{
			case 48:
				break;
			case 49:
				xuatCauHoi(l,y);
				gotoxy(20,y);
				system("pause");
				break;
			case 50:
				themCauHoiVaoFile(l);
				break;
			case 51:
				y=5;
				xuatCauHoi(l,y);
				gotoxy(20,y);
				printf("Nhap stt cau hoi can xoa: ");
				cin>>stt;
				if(stt<1 || stt > l.soLuong)
				{
					MessageBox(NULL,"Xoa khong thanh cong","Thong bao",MB_OK|MB_ICONINFORMATION);
				}	
				else
				{
					xoaAW(l, stt);
					capNhatSTTSauXoa(l);
					capNhatFileCauHoi(l);
					MessageBox(NULL,"Xoa thanh cong","Thong bao",MB_OK|MB_ICONINFORMATION);
					
				}
				break;
			case 52:
				doiMK();
				break;
			case 53:
				int so;
				y=5;
				xuatCauHoi(l,y);
				gotoxy(20,y);
				printf("Nhap STT cau hoi can chinh sua:");
				cin>>so;
				capNhatCauHoi(l,so);
				break;
			default:
				printf("\nBan hay chon lai cho dung");
				system("pause");
				break;
				
		}
	}
}
void endProgram()
{
	int x=0, y=10;
	while(true)
	{
		system("cls");
		gotoxy(x,y);
		printf("Program is coded by:");
		gotoxy(x,y+1);
		printf("van Khai");
		gotoxy(x,y+2);
		printf("Dinh Linh");
		gotoxy(x,y+3);
		printf("Chi Ton");
		gotoxy(x,y+4);
		printf("Thi Huyen");
		gotoxy(x,y+5);
		printf("Van Hai");
		Sleep(10);
		x++;
		if(x==35)
			return;		
	}
}
void passSao(char s[])
{
	char c='a',pass[20];
	int i=0;
	fflush(stdin);
	while(c!=13)
	{
		if(kbhit())//true neu phim duoc nhan
		{	
			c=getch();
			if(c!=8 && c!= 13)
			{
				cout<<"*";
				pass[i]=c;
				i++;
			}
			else if(c==8)
			{
				cout<<"\b \b";
				i--;
			}
		}
	}
	pass[i]='\0';
	strcpy(s,pass);
}
void deleteALL(LIST &l)
{
	NODE *p=l.first;
	while(p!=NULL)
	{
		l.first=p->link;
		delete p;
		p=l.first;
	}
}
void menu()
{
	ifstream fp;
	fp.open("menu.txt",ios_base::in);
	string s;
	int y=2;
	while(!fp.eof())
	{
		getline(fp,s);
		gotoxy(25,y++);
		cout<<s;
	}
}
void InitDK(LIST_DK &l)
{
	l.first=l.last=NULL;

}
NODE_DK *getNodeDK(DANGKY x)
{
	NODE_DK *p=new NODE_DK;
	if(p==NULL)
		return NULL;
	p->data=x;
	p->link=NULL;
	return p;	
}
void addLastDK(LIST_DK &l,DANGKY x)
{
	NODE_DK *p = getNodeDK(x);
	if(l.first == NULL)
	{
		l.first=l.last=p;
	
	}	
	else
	{
		l.last->link=p;
		l.last=p;
	}
}
void docFile(LIST_DK &l)
{
	DANGKY x;
	ifstream fp;
	fp.open("dangKi.txt",ios_base::in);
	while(!fp.eof())
	{
		getline(fp,x.tk);
		getline(fp,x.mk);
		addLastDK(l,x);	
	}
	fp.close();
}
int tim(LIST_DK &l,DANGKY x)
{
	docFile(l);
	NODE_DK *p=l.first;
	while(p!=NULL)
	{
		if(p->data.tk.compare(x.tk)==0)
			return 1;
		p=p->link;
	}
	return 0;
	
}
void dangKyTK(LIST_DK &l)
{
	DANGKY x;
	string mk1;
	while(true)
	{
		char MK[20],MK1[20];
		gotoxy(25,3);
		cout<<"Vui long dien thong tin";
		gotoxy(25,5);
		printf("Nhap ten TK :");
		fflush(stdin);
		getline(cin,x.tk);
		if(tim(l,x)==1)
		{
			gotoxy(25,7);
			printf("TK da ton tai !!!\n");
			Sleep(2000);
			system("cls");
		}
		else 
		{
			gotoxy(25,7);
			printf("Nhap MK :");
			passSao(MK);
			x.mk=MK;
			gotoxy(25,9);
			printf("Nhap lai MK :");
			passSao(MK1);
			mk1=MK1;
			if(x.mk.compare(mk1)==0)
			{
				gotoxy(25,11);
				printf("Dang Ki Thanh Cong !!!");
				Sleep(2000);
				addLastDK(l,x);
				ofstream fp;
				fp.open("dangKi.txt",ios_base::app);
				// noi dung vao phia sau tep
				fp<<"\n";
				fp<<x.tk<<endl;
				fp<<x.mk;
				fp.close();
			}
			else
			{
				gotoxy(25,11);
				printf("Mat khau khong hop le !!!");
				Sleep(2000);
			}	
			
			break;
		}
	}	
}
int dangNhap(LIST_DK l,string tk, string mk)
{
	int d=0;
	DANGKY x;
	ifstream fp;
	fp.open("dangKi.txt",ios_base::in);
	while(!fp.eof())  // Khi con tro cua tep tro vào cuoi tep thi nó se return true
	{
		getline(fp,x.tk);
		getline(fp,x.mk);
		addLastDK(l,x);	
		if(tk.compare(x.tk)==0&&mk.compare(x.mk)==0)
			d++;
	}
	return d;
}
void chucNangThiSinh()
{
	
	char luachon='a';
	while(luachon!=48)
	{
		system("cls");
		menu();
		gotoxy(40,12);
     	printf("0. Quay lai");
		gotoxy(40,13);
		cout<<"1. Vao thi";
		gotoxy(40,14);
		printf("2. Luat Thi");
		gotoxy(40,17);
		printf("Nhap lua chon: ");
		fflush(stdin);
		luachon=getch();	
		system("cls");
		switch(luachon)
		{
			case 48:
		 		break;
			case 49:
				LIST l;
				Init(l);
				themVaoList(l);
				system("cls");
			
				Thi(l);
				deleteALL(l);
				break;
			case 50:
				luat();
				Sleep(3000);
				break;
			default:
				gotoxy(40,14);
				printf("Ban hay chon lai cho dung");
				Sleep(1500);
				break;
				
		}
	}
}
void thisinh()
{
	LIST_DK l;
	InitDK(l);
	char luachon='a';
	string tk,mk;
	char MK[20];
	while(luachon!=48)
	{
		system("cls");
		menu();
		gotoxy(40,12);
	    printf("0. Quay lai");
		gotoxy(40,13);
		printf("1. Dang ki");
		gotoxy(40,14);
		printf("2. Dang nhap");
		gotoxy(40,17);
		printf("Nhap lua chon: ");
		luachon=getch();
		system("cls");
		switch(luachon)
		{
			case 48:
				break;
			case 49:
				dangKyTK(l);
				break;
			case 50:
				gotoxy(25,7);
				printf("Moi ban dang nhap tai khoan");
				gotoxy(25,9);
				printf("Nhap TK :");
				fflush(stdin);
				cin>>tk;
				gotoxy(25,11);
				printf("Nhap MK :");
				passSao(MK);
				mk=MK;
				if(dangNhap(l,tk,mk)==0)
				{
					gotoxy(25,13);
					printf("Dang nhap khong thanh cong");
					Sleep(2000);
				}
				else
					{
						gotoxy(25,13);
					printf("Dang nhap thanh cong !!!");
						Sleep(2000);
						chucNangThiSinh();
					}
				break;
			default:
				gotoxy(40,14);
				printf("\nBan hay chon lai cho dung");
				Sleep(1500);
				break;
		}
	}
}
void capNhatCauHoi(LIST	&l,int maCauHoi)
{
	NODE *p=search(l,maCauHoi);
	if(p==NULL)return;
	int y=5,luachon;
	char c='a';
	system("cls");
	gotoxy(25,5);
	printf("\t\tCap nhat cau hoi:\n");
	while(c!=48)
	{
		gotoxy(25,6);
		cout <<"0.Ket thuc\n";
		gotoxy(25,7);
		printf("1.Cap nhat noi dung cau hoi\n");
		gotoxy(25,8);
		printf("2.Cap nhat dap an A\n");
		gotoxy(25,9);
		printf("3.Cap nhat dap an B\n");
		gotoxy(25,10);
	 	printf("4.Cap nhat dap an C\n");
	 	gotoxy(25,11);
	    printf("5.Cap nhat dap an D\n");
	 	gotoxy(25,12);
	 	printf("6.Cap nhat dap an dung\n");
	 	c=getch();
	 	system("cls");
	 	switch(c)
	 	{
	 		case 49:
	 			
	 			fflush(stdin);
	 			gotoxy(25,5);
	 			printf("Vui long nhap lai noi dung cau hoi:");	
	 			getline(cin,p->data.cauHoi);
	 			system("cls");
	 			break;
	 		case 50:
	 			
	 			fflush(stdin);
	 			gotoxy(25,5);
	 			printf("Vui long nhap lai dap an A:");
	 			getline(cin,p->data.cauA);
	 			system("cls");
	 			break;
	 		case 51:
			
	 			fflush(stdin);
	 			gotoxy(25,5);
 				printf("Vui long nhap lai dap an B:");
	 			getline(cin,p->data.cauB);
	 			system("cls");
	 			break;
	 		
	 		case 52:
	 			
	 			fflush(stdin);
	 			gotoxy(25,5);
				printf("Vui long nhap lai dap an C:");
	 			getline(cin,p->data.cauC);
	 			system("cls");
	 			break;
	 		
	 		case 53:
	 		
	 			fflush(stdin);
	 			gotoxy(25,5);
				printf("Vui long nhap lai dap an D:");
	 			getline(cin,p->data.cauD);
	 			system("cls");
	 			break;
	 		
	 		case 54:
	 			fflush(stdin);
	 			gotoxy(25,y++);
				printf("Vui long nhap lai dap an chinh xac:");
	 			while(true)
			 	{
	 				getline(cin,p->data.dapAn);
	 				char s[p->data.dapAn.size()];
	 				strcpy(s,p->data.dapAn.c_str());
	 				if(stricmp(s,"a")!=0&&stricmp(s,"b")!=0&&stricmp(s,"c")!=0&&stricmp(s,"d")!=0)
 					{
				 		gotoxy(25,y++);
				 		printf("Nhap lai: ");
				 	}
				 	else
				 		break;
				}
 				system("cls");
		 		break;	
			default:
				break;	
 		}		
	}		
	capNhatFileCauHoi(l);
}
NODE_DK *searchTK(LIST_DK &l, string tk)
{
	NODE_DK *p=l.first;
	while(p!=NULL)
	{
		if(p->data.tk.compare(tk)==0)
			return p;
		p=p->link;
	}
	return NULL;
}
