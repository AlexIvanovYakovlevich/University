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
	float f;
void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{

	float x;
	x = StrToInt(Edit1->Text);
	if(RadioGroup1->ItemIndex == 0){
		f = (exp(x)-exp(-x))/2;
	}
	else if (RadioGroup1->ItemIndex == 1) {
			f = x*x;
		 }
		 else {
         	f = exp(x);
		 }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	float x,y;
	x = StrToInt(Edit1->Text);
	y = StrToInt(Edit2->Text);

	if (x/y > 0) {
		Edit3->Text = FloatToStr(log(f) + pow(abs(f),1/3));
	}
	else if (x/y < 0) {
			Edit3->Text = FloatToStr(log(abs(f/y)) * pow(x * y, 3));
		 }
		 else{
			Edit3->Text = FloatToStr(pow(f * f + y, 3));
		 }

}
//---------------------------------------------------------------------------
