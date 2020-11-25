//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//���������� ������� ���������� ������
int GetLine(int f, AnsiString *st);
//���������� ���������
struct TStudent
{
AnsiString Fam,Inic,Grup,D1,D2;
};
//---------------------------------------------------------------------------
float
i;
void __fastcall TForm1::Button6Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
int i,j;
int index,index0;
int num;
int Lstr;
String Lst;
TStudent Student1;
Student1.Fam = InputBox("���� ������ � ��������", "������� �������",Name);
Student1.Inic = InputBox("���� ������ � ��������", "������� ��������", "�����");
Student1.Grup = InputBox("���� ������ � ��������", "������� ������","�����");
Student1.D1 = InputBox("���� ������ � ��������", "��", "�����");
Student1.D2 = InputBox("���� ������ � ��������", "������� ������ �� ��", "�����");
//����������� ����� ����� � �������
index0 = StringGrid1->RowCount;
// ����������� ������ ��������� ������
for (i=0; i <index0;i++)
{
Lst= StringGrid1->Cells[1][i];
Lstr =Lst.Length(); //����������� ����� ������ � 1-� ������� i-�� ������
if (Lstr==0) break;
index = i; // ������ ��������� ������
}
//�������� ������������� ���������� ����� ����� �� 1
if(index <(index0 -1)) StringGrid1->RowCount=(index0+1);
num=index +1; // ������ ��������� ������
StringGrid1->Cells[0][num]= num;// ������ ������ �� �������
//���������� ��������� ������ � �������
StringGrid1->Cells[1][num]=Student1.Fam;
StringGrid1->Cells[2][num]=Student1.Inic;
StringGrid1->Cells[3][num]=Student1.Grup;
StringGrid1->Cells[4][num]=Student1.D1;
StringGrid1->Cells[5][num]=Student1.D2;
}
//--------------------------------------------------------------------
//������� ��� ��������� ������� ��������� ������ ���������� �������

//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
StringGrid1->Enabled=true; //�������� ������� � �������
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
StringGrid2->Visible = true;
AnsiString s1,s2;
s1 = Edit1->Text;
for (i=1; i<=StringGrid1->RowCount; i++)
{
s2= StringGrid1->Cells[1][i];
if(s1==s2) break;
}
StringGrid2->Rows[1]=StringGrid1->Rows[i];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
int f; //���������� �����
//������� ������������ ����, ���� ��� ���, ������� �����
if (FileExists("tab1.grd"))
f= FileOpen("tab1.grd",fmOpenWrite); // ������� ���� �� ������
else
f = FileCreate("tab1.grd");
if (f!=-1)
{
for (int i =1; i<StringGrid1->RowCount; i++)
{
// ������������ ������, �������������� ��������� ����� ������ � ������� �������
AnsiString st = StringGrid1->Rows[i]->DelimitedText+"\r\n";
FileWrite(f,st.c_str(), st.Length()); //������ ������ � ����
}
FileClose(f);//�������� �����
}
else
ShowMessage("������ ������� � �����");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
int f;
AnsiString st;
bool f1=true;
if((f = FileOpen("tab1.grd",fmOpenRead))==-1)
return;
while (GetLine(f,&st) !=0)
{
if (f1)
{
StringGrid1->Rows[StringGrid1->Row] -> DelimitedText= st;
f1= false;
} else
{
StringGrid1->RowCount++;
StringGrid1->Row = StringGrid1->RowCount -1;
StringGrid1->Rows[StringGrid1->Row]-> DelimitedText=st;
}
}
FileClose(f);
}
//������ �� ����� ������ ��������
//�� ������� ������� �� ������� ����� ������
//�������� ������� ���������� ����������� ��������
int GetLine (int f, AnsiString *st)
{
unsigned char buf[256]; //������ �������� ������ ��� ���������� �������� ������
unsigned char *p = buf;// ��������� �� ������
int n;//���������� ����������� ����
int len = 0;// ����� ������
n = FileRead(f,p,1); // ����������� ������� ���������� ���� �� �����
while (n!= 0)
{
if(*p =='\r')
{
n = FileRead(f,p,1); //���������� �������� ������
break;
}
len++;
p++;
n = FileRead(f,p,1);
}
*p = '\0';
if (len !=0)// ���� ����� ������ �� ����� 0. ��������� ����� �� ������ ������������ � ���������� st
st -> printf("%s",buf);
return len;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
StringGrid1->Cells[0][0]= "� �/�";
StringGrid1->Cells[1][0]= "�������";
StringGrid1->Cells[2][0]= "��������";
StringGrid1->Cells[3][0]= "������";
StringGrid1->Cells[4][0]= "��";
StringGrid1->Cells[5][0]= "��";
StringGrid1->Options << goEditing;// ���������� ����������������� ������� � ����� �������
StringGrid1->Options << goTabs; // ����������� �� ����� ������� � ������� ������� Tab
//������������ ������������ �������� ������� 2
StringGrid2->Cells[0][0]= "� �/�";
StringGrid2->Cells[1][0]= " ������� ";
StringGrid2->Cells[2][0]= " �������� ";
StringGrid2->Cells[3][0]= " ������ ";
StringGrid2->Cells[4][0]= " ��";
StringGrid1->Cells[5][0]= " ��";
}
//---------------------------------------------------------------------------
