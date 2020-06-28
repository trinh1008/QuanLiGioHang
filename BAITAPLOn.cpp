#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sp_st 
{	char tensp[30]; 
	int gia;
 	int soluong;
};
struct 
{ 	char tenkhachhang[30];
 	char diachi[50];
 	int sosanpham;
 	struct sp_st dssp[30]; 
}giohang_st;
void taogiohang()
{	printf("Nhap Ten Khach Hang: ");
	fflush(stdin);
	gets(giohang_st.tenkhachhang);
	printf("Nhap Dia Chi: ");
	fflush(stdin);
	gets(giohang_st.diachi);
	giohang_st.sosanpham=0;	
}
int chonhang()
{	int GH;
	int i=0;
while(GH!=0)	
{   
	printf("1. Banh mi\n");
	printf("2. Mi tom\n");
    int luachon; 
    printf("Nhap vao lua chon cua ban\n"); 
    scanf("%d",&luachon);
    switch(luachon)
    {
    	case 1: {printf("\nTen San Pham: Banh mi");
	fflush(stdin);
	strcpy(giohang_st.dssp[i].tensp,"Banh mi");
	printf("\nGia: 5000 VND "); giohang_st.dssp[i].gia=5000;
	printf("Nhap So Luong can mua: ");
	scanf("%d",&giohang_st.dssp[i].soluong);
	printf("\n Khach Hang co muon tiep tuc chon hang Khong: ");
	printf("\n Nhap 1 neu Co va Nhap 0 neu Khong : ");
	scanf("%d", &GH); 
	giohang_st.sosanpham++;
	i++;
	
	break; }
        case 2: {printf("\nTen San Pham: Mi tom");
	fflush(stdin);
	strcpy(giohang_st.dssp[i].tensp,"Mi tom");
	printf("\nGia: 3000 VND "); giohang_st.dssp[i].gia=3000;
	printf("Nhap So Luong can mua: ");
	scanf("%d",&giohang_st.dssp[i].soluong);
	giohang_st.sosanpham++;
	i++;
	printf("\n Khach Hang co muon tiep tuc chon hang Khong: ");
	printf("\n Nhap 1 neu Co va Nhap 0 neu Khong : ");
	scanf("%d", &GH); break;}
    }
	
}
}
void xemchitiet()
{ 	int i,j;
	struct sp_st Doi;
	printf("\n %-10s    %-10s    %-10s    %-10s \n","STT","Ten San Pham","Gia","So Luong");
	for( i=0;i<giohang_st.sosanpham-1;i++)
	{
			for(j=i+1;j<giohang_st.sosanpham;j++)
		{
				if(strcmp(giohang_st.dssp[i].tensp,giohang_st.dssp[j].tensp)>0)
				{
				Doi=giohang_st.dssp[i];
				giohang_st.dssp[i]=giohang_st.dssp[j];
				giohang_st.dssp[j]=Doi;
}}}
	for(i=0;i<giohang_st.sosanpham;i++)
{
	printf("%-10d    %-10s      %-10d     %-10d \n",i+1,giohang_st.dssp[i].tensp,giohang_st.dssp[i].gia,giohang_st.dssp[i].soluong);			
}}
void loaibomathang(){
	int n,i;
	do
	{
	printf("\nCan loai bo san pham thu may:  ");
	scanf("%d",&n);
	if(n<1 || n>giohang_st.sosanpham) printf("\nVi tri san phan khong hop le. Xin nhap lai vi tri!  ");
	}while(n<1 || n>giohang_st.sosanpham);
	for( i=n-1;i<giohang_st.sosanpham;i++)
		giohang_st.dssp[i]=giohang_st.dssp[i+1];
	giohang_st.sosanpham=giohang_st.sosanpham-1;
}

void ghi(){
	FILE *fp;
	int i;
	fp=fopen("E:\\khanh.dat","w");
	
	fprintf(fp,"\n %-10s    %-10s    %-10s    %-10s \n","STT","Ten San Pham","Gia","So Luong");
	for(i=0;i<giohang_st.sosanpham;i++)
{
	fprintf(fp,"%-10d    %-10s      %-10d     %-10d \n",i+1,giohang_st.dssp[i].tensp,giohang_st.dssp[i].gia,giohang_st.dssp[i].soluong);			
}
	fclose(fp);

	}
void doc(){
	FILE *fp;
	int i;
	fp=fopen("E:\\khanh.dat","r");
	fscanf(fp,"\n %-10s    %-10s    %-10s    %-10s \n","STT","Ten San Pham","Gia","So Luong");
	for(i=0;i<giohang_st.sosanpham;i++)
{
	fscanf(fp,"%-10d    %-10s      %-10d     %-10d \n",i+1,&giohang_st.dssp[i].tensp,&giohang_st.dssp[i].gia,&giohang_st.dssp[i].soluong);			
}

	fclose(fp);
}
void luu(){
	ghi();
	doc();
}
void Menu()
{  int a;
do{
        printf("\n\n********************************************************************\n");
        printf("**       CHUONG TRINH QUAN LY GIO HANG                            **\n");
        printf("**        1. Tao gio hang                                         **\n");
        printf("**        2.  Chon hang                                           **\n");
        printf("**        3. Xem chi tiet gio hang                                **\n");
        printf("**        4. Loai bo mot mat hang                                 **\n"); 
		printf("**        5.Ghi toan bo noi dung vao tep van ban  cart.dat        **\n");
        printf("**        6. Thoat                                                **\n");
      	printf("********************************************************************\n");

	 	printf("          Lua chon 1->6:");
scanf("%d",&a);
switch(a){
	case 1: {taogiohang(); break;}
	case 2:	{chonhang(); break;}
	case 3: {xemchitiet(); break;}
	case 4: {loaibomathang(); break;}
	case 5:	{luu(); break;}
	default: break;
}
}while(a!=6);
}
int main()
{ 	Menu();

return 0;
}
