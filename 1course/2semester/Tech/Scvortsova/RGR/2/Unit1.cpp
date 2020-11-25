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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int arr[3][3];
	int n, m;
	n = 0;
	m = 0;

	for(int i = 0; i < 10; i++){
			TEdit* edit;
			edit = dynamic_cast<TEdit*>(Components[i]);
			if(edit){
				if (n%3 == 0) {
					m++;
					n = 0;
				}
				arr[m-1][n] = StrToInt(edit->Text);
				n++;
			}
	}

	for (int i = 0; i < 3; i++) {
        Edit10->Text = Edit10->Text + IntToStr(arr[i][i]) + "; ";
	}

}
//---------------------------------------------------------------------------
