#pragma once

#include <math.h>
#include "mertlib.h"
namespace asasdasd {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bol;
	private: System::Windows::Forms::Button^  topla;
	protected: 

	protected: 

	private: System::Windows::Forms::Button^  carp;
	private: System::Windows::Forms::Button^  cikar;
	private: System::Windows::Forms::Button^  esittir;



	private: System::Windows::Forms::Button^  alti;
	private: System::Windows::Forms::Button^  uc;
	private: System::Windows::Forms::Button^  iki;
	private: System::Windows::Forms::Button^  bir;





	private: System::Windows::Forms::Button^  dort;

	private: System::Windows::Forms::Button^  sifir;
	private: System::Windows::Forms::Button^  dokuz;
	private: System::Windows::Forms::Button^  sekiz;
	private: System::Windows::Forms::Button^  yedi;
	private: System::Windows::Forms::Button^  bes;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  Sil;
	private: System::Windows::Forms::Button^  k_kok;
	private: System::Windows::Forms::Button^  mod;
	private: System::Windows::Forms::Button^  negatif;
	private: System::Windows::Forms::Button^  fakt;
	private: System::Windows::Forms::Button^  by;


















	protected: 











	protected: 

	protected: 




	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bol = (gcnew System::Windows::Forms::Button());
			this->topla = (gcnew System::Windows::Forms::Button());
			this->carp = (gcnew System::Windows::Forms::Button());
			this->cikar = (gcnew System::Windows::Forms::Button());
			this->esittir = (gcnew System::Windows::Forms::Button());
			this->alti = (gcnew System::Windows::Forms::Button());
			this->uc = (gcnew System::Windows::Forms::Button());
			this->iki = (gcnew System::Windows::Forms::Button());
			this->bir = (gcnew System::Windows::Forms::Button());
			this->dort = (gcnew System::Windows::Forms::Button());
			this->sifir = (gcnew System::Windows::Forms::Button());
			this->dokuz = (gcnew System::Windows::Forms::Button());
			this->sekiz = (gcnew System::Windows::Forms::Button());
			this->yedi = (gcnew System::Windows::Forms::Button());
			this->bes = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Sil = (gcnew System::Windows::Forms::Button());
			this->k_kok = (gcnew System::Windows::Forms::Button());
			this->mod = (gcnew System::Windows::Forms::Button());
			this->negatif = (gcnew System::Windows::Forms::Button());
			this->fakt = (gcnew System::Windows::Forms::Button());
			this->by = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bol
			// 
			this->bol->Location = System::Drawing::Point(398, 118);
			this->bol->Name = L"bol";
			this->bol->Size = System::Drawing::Size(39, 41);
			this->bol->TabIndex = 0;
			this->bol->Text = L"/";
			this->bol->UseVisualStyleBackColor = true;
			// 
			// topla
			// 
			this->topla->Location = System::Drawing::Point(353, 118);
			this->topla->Name = L"topla";
			this->topla->Size = System::Drawing::Size(39, 40);
			this->topla->TabIndex = 1;
			this->topla->Text = L"+";
			this->topla->UseVisualStyleBackColor = true;
			this->topla->Click += gcnew System::EventHandler(this, &Form1::topla_Click);
			// 
			// carp
			// 
			this->carp->Location = System::Drawing::Point(398, 74);
			this->carp->Name = L"carp";
			this->carp->Size = System::Drawing::Size(39, 39);
			this->carp->TabIndex = 2;
			this->carp->Text = L"*";
			this->carp->UseVisualStyleBackColor = true;
			this->carp->Click += gcnew System::EventHandler(this, &Form1::carp_Click);
			// 
			// cikar
			// 
			this->cikar->Location = System::Drawing::Point(353, 73);
			this->cikar->Name = L"cikar";
			this->cikar->Size = System::Drawing::Size(39, 39);
			this->cikar->TabIndex = 3;
			this->cikar->Text = L"-";
			this->cikar->UseVisualStyleBackColor = true;
			this->cikar->Click += gcnew System::EventHandler(this, &Form1::cikar_Click);
			// 
			// esittir
			// 
			this->esittir->Location = System::Drawing::Point(356, 9);
			this->esittir->Name = L"esittir";
			this->esittir->Size = System::Drawing::Size(81, 57);
			this->esittir->TabIndex = 4;
			this->esittir->Text = L"=";
			this->esittir->UseVisualStyleBackColor = true;
			this->esittir->Click += gcnew System::EventHandler(this, &Form1::esittir_Click);
			// 
			// alti
			// 
			this->alti->Location = System::Drawing::Point(12, 130);
			this->alti->Name = L"alti";
			this->alti->Size = System::Drawing::Size(39, 40);
			this->alti->TabIndex = 5;
			this->alti->Text = L"6";
			this->alti->UseVisualStyleBackColor = true;
			this->alti->Click += gcnew System::EventHandler(this, &Form1::alti_Click);
			// 
			// uc
			// 
			this->uc->Location = System::Drawing::Point(102, 84);
			this->uc->Name = L"uc";
			this->uc->Size = System::Drawing::Size(39, 40);
			this->uc->TabIndex = 6;
			this->uc->Text = L"3";
			this->uc->UseVisualStyleBackColor = true;
			this->uc->Click += gcnew System::EventHandler(this, &Form1::uc_Click);
			// 
			// iki
			// 
			this->iki->Location = System::Drawing::Point(57, 84);
			this->iki->Name = L"iki";
			this->iki->Size = System::Drawing::Size(39, 40);
			this->iki->TabIndex = 7;
			this->iki->Text = L"2";
			this->iki->UseVisualStyleBackColor = true;
			this->iki->Click += gcnew System::EventHandler(this, &Form1::iki_Click);
			// 
			// bir
			// 
			this->bir->Location = System::Drawing::Point(12, 84);
			this->bir->Name = L"bir";
			this->bir->Size = System::Drawing::Size(39, 40);
			this->bir->TabIndex = 8;
			this->bir->Text = L"1";
			this->bir->UseVisualStyleBackColor = true;
			this->bir->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// dort
			// 
			this->dort->Location = System::Drawing::Point(147, 84);
			this->dort->Name = L"dort";
			this->dort->Size = System::Drawing::Size(39, 40);
			this->dort->TabIndex = 9;
			this->dort->Text = L"4";
			this->dort->UseVisualStyleBackColor = true;
			this->dort->Click += gcnew System::EventHandler(this, &Form1::dort_Click);
			// 
			// sifir
			// 
			this->sifir->Location = System::Drawing::Point(192, 130);
			this->sifir->Name = L"sifir";
			this->sifir->Size = System::Drawing::Size(39, 40);
			this->sifir->TabIndex = 10;
			this->sifir->Text = L"0";
			this->sifir->UseVisualStyleBackColor = true;
			this->sifir->Click += gcnew System::EventHandler(this, &Form1::sifir_Click);
			// 
			// dokuz
			// 
			this->dokuz->Location = System::Drawing::Point(147, 130);
			this->dokuz->Name = L"dokuz";
			this->dokuz->Size = System::Drawing::Size(39, 40);
			this->dokuz->TabIndex = 11;
			this->dokuz->Text = L"9";
			this->dokuz->UseVisualStyleBackColor = true;
			this->dokuz->Click += gcnew System::EventHandler(this, &Form1::dokuz_Click);
			// 
			// sekiz
			// 
			this->sekiz->Location = System::Drawing::Point(102, 130);
			this->sekiz->Name = L"sekiz";
			this->sekiz->Size = System::Drawing::Size(39, 40);
			this->sekiz->TabIndex = 12;
			this->sekiz->Text = L"8";
			this->sekiz->UseVisualStyleBackColor = true;
			this->sekiz->Click += gcnew System::EventHandler(this, &Form1::sekiz_Click);
			// 
			// yedi
			// 
			this->yedi->Location = System::Drawing::Point(57, 130);
			this->yedi->Name = L"yedi";
			this->yedi->Size = System::Drawing::Size(39, 40);
			this->yedi->TabIndex = 13;
			this->yedi->Text = L"7";
			this->yedi->UseVisualStyleBackColor = true;
			this->yedi->Click += gcnew System::EventHandler(this, &Form1::yedi_Click);
			// 
			// bes
			// 
			this->bes->Location = System::Drawing::Point(192, 84);
			this->bes->Name = L"bes";
			this->bes->Size = System::Drawing::Size(39, 40);
			this->bes->TabIndex = 14;
			this->bes->Text = L"5";
			this->bes->UseVisualStyleBackColor = true;
			this->bes->Click += gcnew System::EventHandler(this, &Form1::bes_Click);
			// 
			// textBox1
			// 
			this->textBox1->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(206, 50);
			this->textBox1->TabIndex = 15;
			// 
			// Sil
			// 
			this->Sil->Location = System::Drawing::Point(224, 12);
			this->Sil->Name = L"Sil";
			this->Sil->Size = System::Drawing::Size(50, 50);
			this->Sil->TabIndex = 16;
			this->Sil->Text = L"C";
			this->Sil->UseVisualStyleBackColor = true;
			this->Sil->Click += gcnew System::EventHandler(this, &Form1::Sil_Click);
			// 
			// k_kok
			// 
			this->k_kok->Location = System::Drawing::Point(306, 119);
			this->k_kok->Name = L"k_kok";
			this->k_kok->Size = System::Drawing::Size(41, 39);
			this->k_kok->TabIndex = 17;
			this->k_kok->Text = L"√";
			this->k_kok->UseVisualStyleBackColor = true;
			this->k_kok->Click += gcnew System::EventHandler(this, &Form1::k_kok_Click);
			// 
			// mod
			// 
			this->mod->Location = System::Drawing::Point(308, 74);
			this->mod->Name = L"mod";
			this->mod->Size = System::Drawing::Size(39, 39);
			this->mod->TabIndex = 18;
			this->mod->Text = L"%";
			this->mod->UseVisualStyleBackColor = true;
			this->mod->Click += gcnew System::EventHandler(this, &Form1::mod_Click);
			// 
			// negatif
			// 
			this->negatif->Location = System::Drawing::Point(306, 18);
			this->negatif->Name = L"negatif";
			this->negatif->Size = System::Drawing::Size(39, 39);
			this->negatif->TabIndex = 19;
			this->negatif->Text = L"-- +";
			this->negatif->UseVisualStyleBackColor = true;
			this->negatif->Click += gcnew System::EventHandler(this, &Form1::negatif_Click);
			// 
			// fakt
			// 
			this->fakt->Location = System::Drawing::Point(260, 119);
			this->fakt->Name = L"fakt";
			this->fakt->Size = System::Drawing::Size(40, 39);
			this->fakt->TabIndex = 20;
			this->fakt->Text = L"!";
			this->fakt->UseVisualStyleBackColor = true;
			this->fakt->Click += gcnew System::EventHandler(this, &Form1::fakt_Click);
			// 
			// by
			// 
			this->by->Location = System::Drawing::Point(376, 164);
			this->by->Name = L"by";
			this->by->Size = System::Drawing::Size(61, 23);
			this->by->TabIndex = 21;
			this->by->Text = L"About";
			this->by->UseVisualStyleBackColor = true;
			this->by->Click += gcnew System::EventHandler(this, &Form1::by_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(447, 190);
			this->Controls->Add(this->by);
			this->Controls->Add(this->fakt);
			this->Controls->Add(this->negatif);
			this->Controls->Add(this->mod);
			this->Controls->Add(this->k_kok);
			this->Controls->Add(this->Sil);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->bes);
			this->Controls->Add(this->yedi);
			this->Controls->Add(this->sekiz);
			this->Controls->Add(this->dokuz);
			this->Controls->Add(this->sifir);
			this->Controls->Add(this->dort);
			this->Controls->Add(this->bir);
			this->Controls->Add(this->iki);
			this->Controls->Add(this->uc);
			this->Controls->Add(this->alti);
			this->Controls->Add(this->esittir);
			this->Controls->Add(this->cikar);
			this->Controls->Add(this->carp);
			this->Controls->Add(this->topla);
			this->Controls->Add(this->bol);
			this->Name = L"Form1";
			this->Text = L"Hesap Makinesi";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			float a,b;
			char op;
			bool birinci_alindi;
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

		 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
					birinci_alindi=false;
					a=0;
					b=0;
					this->textBox1->Text=""+0;
			 }
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "1";
			 }
	private: System::Void sekiz_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "8";
			 }
	private: System::Void yedi_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "7";
			 }
	private: System::Void dokuz_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "9";
			 }
	private: System::Void alti_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "6";
			 }
    private: System::Void bes_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "5";
			 }
	 private: System::Void dort_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "4";
			  }
	  private: System::Void uc_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "3";
			 }
   private: System::Void iki_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "2";
			 }
	private: System::Void bir_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "1";
			 }
	private: System::Void sifir_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "0";
			 }
private: System::Void topla_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				if(!a)
				{
					a = float::Parse(this->textBox1->Text);
					this->textBox1->Text="";
					//op='+';
				}
				else
				{
					b= float::Parse(this->textBox1->Text);
					a=a+b;
					this->textBox1->Text=""+a;
				}
			 }
private: System::Void cikar_Click(System::Object^  sender, System::EventArgs^  e) {
			 
		 }

private: System::Void fakt_Click(System::Object^  sender, System::EventArgs^  e) {
			 a= int::Parse(this->textBox1->Text);
			 this->textBox1->Text="";
			 if(a<20)
			 this->textBox1->Text=""+fakt_hesapla(a);
			 
		 }
private: System::Void by_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("Yazdıım İlk .Net Program.. \n Kullandığınız İçin Teşekkürler..",">>by Mert<<");
		 }
};