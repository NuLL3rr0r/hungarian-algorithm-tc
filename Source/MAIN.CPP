#include <conio.h>
#include <iostream.h>

const int size=3;

void read_MATx(int x[][size])
{
	clrscr();
	cout<<endl<<"Please Enter The X Matrix: "<<endl;
	for (int i=0;i<size;i++)
	{
		cout<<"row["<<i<<"]: ";
		for (int j=0;j<size;j++)
		{
			cin>>x[i][j];
			}
	}
	cout<<endl<<"\tThe arrays is accept; press any key for return...";
	getch();
}

void read_MinofRow_MATx(int x[][size],int xx[][size])
{
	int c[size][size];
	int cc[size][size];
	int ccc[size][size];
	int Cmin;
	int i,j;

	clrscr();
	cout<<"The contents of X matrix is:";
	for (i=0;i<size;i++)
	{
		cout<<endl<<endl<<"\t";
		for (j=0;j<size;j++)
			cout<<x[i][j]<<"   ";
	}
	getch();
	for (i=0;i<size;i++)
	{
		cout<<endl<<endl;
		Cmin=x[i][0];
		for (j=1;j<size;j++)
			if (Cmin>x[i][j]) Cmin=x[i][j];
		cout<<"The minimum of row["<<i<<"] from X matrix is: "<<Cmin;
		for (j=0;j<size;j++)
			c[i][j]=Cmin;
	}
	getch();
	cout<<endl<<endl<<"The contents of C matrix is:";
	for (i=0;i<size;i++)
	{
		cout<<endl<<endl<<"\t";
		for (j=0;j<size;j++)
			cout<<c[i][j]<<"   ";
	}
	getch();
	cout<<endl<<endl<<"The subtraction of 'X & C' matrixs (Result CC matrix):";
	for (i=0;i<size;i++)
	{
		cout<<endl<<endl<<"\t";
		for (j=0;j<size;j++)
		{
			cc[i][j]=x[i][j]-c[i][j];
			cout<<cc[i][j]<<"   ";
		}
	}
	getch();
	for (j=0;j<size;j++)
	{
		cout<<endl<<endl;
		Cmin=cc[0][j];
		for (i=1;i<size;i++)
			if (Cmin>cc[i][j]) Cmin=cc[i][j];
		cout<<"The minimum of col["<<j<<"] from cc matrix is: "<<Cmin;
		for (i=0;i<size;i++)
			ccc[i][j]=Cmin;
	}
	getch();
	cout<<endl<<endl<<"The contents of CCC matrix is:";
	for (i=0;i<size;i++)
	{
		cout<<endl<<endl<<"\t";
		for (j=0;j<size;j++)
			cout<<ccc[i][j]<<"   ";
	}
	getch();
	cout<<endl<<endl<<"The subtraction of 'CC & CCC' matrixs (Result XX matrix):";
	for (i=0;i<size;i++)
	{
		cout<<endl<<endl<<"\t";
		for (j=0;j<size;j++)
		{
			xx[i][j]=cc[i][j]-ccc[i][j];
			cout<<xx[i][j]<<"   ";
		}
	}
	cout<<endl<<endl<<"\t\t\tPress any key for return...";
	getch();
}

void Erase_RowCol_MATxx(int xx[][size],int p[][size-1],int pp[][size-1])
{
	int Row[size],Col[size],zeroCol,zeroRow;
	int MaxRow,MaxCol;
	int i,j,k;
	int s;
	int ii=0,jj=0;

	int w[size-1][size-1],b[size-1][size-1],a[size-1][size-1];

	for (i=0;i<size-1;i++)
		for (j=0;j<size-1;j++)
		{
			w[i][j]=1;
			b[i][j]=-1;
		}

	clrscr();
	cout<<"The contnets of P matrix:";
	for (i=0;i<size;i++)
	{
		zeroRow=0;
		zeroCol=0;
		for (j=0;j<size;j++)
		{
			if (xx[i][j]==0) zeroRow+=1;
			if (xx[j][i]==0) zeroCol+=1;
		}
		Row[i]=zeroRow;
		Col[i]=zeroCol;
	}
	zeroRow=0;
	zeroCol=0;
	for (i=0;i<size;i++)
	{
		if (Row[i]>zeroRow)
		{
			MaxRow=i;
			zeroRow=Row[i];
		}
		if (Col[i]>zeroCol)
		{
			MaxCol=i;
			zeroCol=Col[i];
		}
	}
	for (i=0;i<size;i++)
	{
		cout<<endl<<endl<<"\t";
		if (MaxRow==i) i++;
		jj=0;
		for (j=0;j<size;j++)
		{
			if (MaxCol==j) j++;
			p[ii][jj]=xx[i][j];
			cout<<p[ii][jj]<<"   ";
			jj++;
			if (jj>=2) j=10;;
		}
		ii++;
		if (ii>=2) i=10;
	}
	getch();
	cout<<endl<<endl<<"The contnets of PP matrix:";
	for (i=0;i<size-1;i++)
	{
		cout<<endl<<endl<<"\t";
		for (j=0;j<size-1;j++)
		{
			if (p[i][j]==0) pp[i][j]=-1;
			else pp[i][j]=1;
			cout<<pp[i][j]<<"   ";
		 }
	}
	getch();
	cout<<endl<<endl<<"[ Result ssgn(W*PP+B) --> a matrix ]";
	for (i=0;i<size-1;i++)
	{
		cout<<endl<<endl<<"\t";
		for (int j=0;j<size-1;j++)
		{
			s=0;
			for (int k=0;k<size-1;k++)
				s+=w[i][k]*pp[k][j];
			s+=b[i][j];
			if (s>=0) s=1;
			else s=-1;
			a[i][j]=s;
			cout<<a[i][j]<<"   ";
		}
	}
	getch();
	int optimize=0;
	for (i=0;i<size-1;i++)
		for (j=0;j<size-1;j++)
			if (a[i][j]!=1) optimize=1;
	if (optimize!=1)
	{
		cout<<endl<<endl<<"The XX matrix is not optimize...";
		int Pmin=p[0][0];
		for (i=0;i<size-1;i++)
			for (j=0;j<size-1;j++)
				if (p[i][j]<Pmin) Pmin=p[i][j];
		for (i=0;i<size;i++)
			for (j=0;j<size;j++)
				if (xx[i][j]!=0) xx[i][j]-=Pmin;
		xx[MaxRow][MaxCol]+=2*Pmin;
		cout<<endl<<endl<<"Optimized XX matrix:";
		for (i=0;i<size;i++)
		{
			cout<<endl<<endl<<"\t";
			for (j=0;j<size;j++)
				cout<<xx[i][j]<<"   ";
		}
	}
	else
	{
		cout<<endl<<endl<<"The XX matrix is optimize...";
		for (i=0;i<size;i++)
		{
			cout<<endl<<endl<<"\t";
			for (j=0;j<size;j++)
				cout<<xx[i][j]<<"   ";
		}
	}
	getch();
}

void final(int xx[][size],int x[][size])
{
	int zero_1st_x=0,zero_1st_y,zero_2nd_x=1,zero_2nd_y,zero_3rd_x=2,zero_3rd_y;
	int zigma;
	int i;

	for (i=0;i<size;i++)
		if (xx[zero_1st_x][i]==0) zero_1st_y=i;
	for (i=0;i<size;i++)
		if (xx[zero_2nd_x][i]==0 && i!=zero_1st_y) zero_2nd_y=i;
	for (i=0;i<size;i++)
		if (i!=zero_1st_y && i!=zero_2nd_y) zero_3rd_y=i;

	zigma=x[zero_1st_x][zero_1st_y]+x[zero_2nd_x][zero_2nd_y]+x[zero_3rd_x][zero_3rd_y];

	clrscr();

	cout<<endl<<endl<<endl<<"\tZ*= "<<zigma;

	getch();
}

void draw_menu()
{
	clrscr();
	cout<<endl<<endl<<endl<<"\t\tI: Read Matrix X";
	cout<<endl<<endl<<endl<<"\t\tII: Expense Matrix";
	cout<<endl<<endl<<endl<<"\t\tIII: Neural Network";
	cout<<endl<<endl<<endl<<"\t\tIV: Final Result";
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\tPlease Select one Choice from Menu [ESC for exit] ==>  ";
}

void main()
{
	int x[size][size];
	int xx[size][size];
	int p[size-1][size-1];
	int pp[size-1][size-1];
	char ch=0;

	do
	{
		draw_menu();
		ch=getch();
		switch(ch)
		{
			case '1':read_MATx(x);
				 break;
			case '2':read_MinofRow_MATx(x,xx);
				 break;
			case '3':Erase_RowCol_MATxx(xx,p,pp);
				 break;
			case '4':final(xx,x);
				 break;
		}
	}while(ch!=27);
}