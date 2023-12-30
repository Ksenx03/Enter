#pragma once
#include "Info.h"
#include "Subjects.h"
#include "Zus.h"
#include "MyMenu.h"
#include "Library.h"
#include "Science.h"
#include "Practice.h"
#include "Diploma.h"


namespace Enter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm1
	/// </summary>

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::Form^ currentForm;
		// ‘ункци€ дл€ открыти€ указанного окна и закрыти€ текущего, если оно есть
		void OpenChildForm(System::Windows::Forms::Form^ childForm) 
		{
			if (currentForm != nullptr)
				currentForm->Hide();  // —крыть текущее окно, если оно есть

			currentForm = childForm;
			childForm->TopLevel = false;
			childForm->AutoScroll = true;

			// ”станавливаем размеры формы
			childForm->Size = panelDesktop->Size;

			// ”станавливаем форме свойство FormBorderStyle в None
			childForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;

			childForm->Dock = System::Windows::Forms::DockStyle::Fill;
			panelDesktop->Controls->Add(childForm);
			childForm->Show();
		}

	public:
		MyForm1(void)
		{
			InitializeComponent();
			currentForm = nullptr;

			MyMenu^ menuForm = gcnew MyMenu();
			OpenChildForm(menuForm);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panelMenu;
	private: System::Windows::Forms::Panel^ panelInfo;
	private: System::Windows::Forms::Button^ buttonDiploma;
	private: System::Windows::Forms::Button^ buttonPractice;
	private: System::Windows::Forms::Button^ buttonScience;
	private: System::Windows::Forms::Button^ buttonLibrary;
	private: System::Windows::Forms::Button^ buttonProgram;
	private: System::Windows::Forms::Button^ buttonSubjects;
	private: System::Windows::Forms::Button^ buttonInfo;
	private: System::Windows::Forms::Panel^ panelDesktop;
	private: System::Windows::Forms::Button^ buttonMenu;
	protected:
	protected:
	protected:
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelMenu = (gcnew System::Windows::Forms::Panel());
			this->buttonDiploma = (gcnew System::Windows::Forms::Button());
			this->buttonPractice = (gcnew System::Windows::Forms::Button());
			this->buttonScience = (gcnew System::Windows::Forms::Button());
			this->buttonLibrary = (gcnew System::Windows::Forms::Button());
			this->buttonProgram = (gcnew System::Windows::Forms::Button());
			this->buttonSubjects = (gcnew System::Windows::Forms::Button());
			this->buttonInfo = (gcnew System::Windows::Forms::Button());
			this->panelInfo = (gcnew System::Windows::Forms::Panel());
			this->buttonMenu = (gcnew System::Windows::Forms::Button());
			this->panelDesktop = (gcnew System::Windows::Forms::Panel());
			this->panelMenu->SuspendLayout();
			this->panelInfo->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelMenu
			// 
			this->panelMenu->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panelMenu->Controls->Add(this->buttonDiploma);
			this->panelMenu->Controls->Add(this->buttonPractice);
			this->panelMenu->Controls->Add(this->buttonScience);
			this->panelMenu->Controls->Add(this->buttonLibrary);
			this->panelMenu->Controls->Add(this->buttonProgram);
			this->panelMenu->Controls->Add(this->buttonSubjects);
			this->panelMenu->Controls->Add(this->buttonInfo);
			this->panelMenu->Controls->Add(this->panelInfo);
			this->panelMenu->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelMenu->Location = System::Drawing::Point(0, 0);
			this->panelMenu->Name = L"panelMenu";
			this->panelMenu->Size = System::Drawing::Size(111, 324);
			this->panelMenu->TabIndex = 8;
			// 
			// buttonDiploma
			// 
			this->buttonDiploma->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->buttonDiploma->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonDiploma->FlatAppearance->BorderSize = 0;
			this->buttonDiploma->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDiploma->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonDiploma->Location = System::Drawing::Point(0, 284);
			this->buttonDiploma->Name = L"buttonDiploma";
			this->buttonDiploma->Size = System::Drawing::Size(111, 40);
			this->buttonDiploma->TabIndex = 7;
			this->buttonDiploma->Text = L"Diploma";
			this->buttonDiploma->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonDiploma->UseMnemonic = false;
			this->buttonDiploma->UseVisualStyleBackColor = false;
			this->buttonDiploma->Click += gcnew System::EventHandler(this, &MyForm1::buttonDiploma_Click);
			// 
			// buttonPractice
			// 
			this->buttonPractice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->buttonPractice->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonPractice->FlatAppearance->BorderSize = 0;
			this->buttonPractice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPractice->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonPractice->Location = System::Drawing::Point(0, 244);
			this->buttonPractice->Name = L"buttonPractice";
			this->buttonPractice->Size = System::Drawing::Size(111, 40);
			this->buttonPractice->TabIndex = 6;
			this->buttonPractice->Text = L"Practice";
			this->buttonPractice->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPractice->UseMnemonic = false;
			this->buttonPractice->UseVisualStyleBackColor = false;
			this->buttonPractice->Click += gcnew System::EventHandler(this, &MyForm1::buttonPractice_Click);
			// 
			// buttonScience
			// 
			this->buttonScience->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->buttonScience->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonScience->FlatAppearance->BorderSize = 0;
			this->buttonScience->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonScience->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonScience->Location = System::Drawing::Point(0, 204);
			this->buttonScience->Name = L"buttonScience";
			this->buttonScience->Size = System::Drawing::Size(111, 40);
			this->buttonScience->TabIndex = 5;
			this->buttonScience->Text = L"Science";
			this->buttonScience->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonScience->UseMnemonic = false;
			this->buttonScience->UseVisualStyleBackColor = false;
			this->buttonScience->Click += gcnew System::EventHandler(this, &MyForm1::buttonScience_Click);
			// 
			// buttonLibrary
			// 
			this->buttonLibrary->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->buttonLibrary->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonLibrary->FlatAppearance->BorderSize = 0;
			this->buttonLibrary->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLibrary->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonLibrary->Location = System::Drawing::Point(0, 164);
			this->buttonLibrary->Name = L"buttonLibrary";
			this->buttonLibrary->Size = System::Drawing::Size(111, 40);
			this->buttonLibrary->TabIndex = 4;
			this->buttonLibrary->Text = L"Library";
			this->buttonLibrary->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonLibrary->UseMnemonic = false;
			this->buttonLibrary->UseVisualStyleBackColor = false;
			this->buttonLibrary->Click += gcnew System::EventHandler(this, &MyForm1::buttonLibrary_Click);
			// 
			// buttonProgram
			// 
			this->buttonProgram->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->buttonProgram->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonProgram->FlatAppearance->BorderSize = 0;
			this->buttonProgram->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgram->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonProgram->Location = System::Drawing::Point(0, 124);
			this->buttonProgram->Name = L"buttonProgram";
			this->buttonProgram->Size = System::Drawing::Size(111, 40);
			this->buttonProgram->TabIndex = 3;
			this->buttonProgram->Text = L"ZUS";
			this->buttonProgram->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgram->UseMnemonic = false;
			this->buttonProgram->UseVisualStyleBackColor = false;
			this->buttonProgram->Click += gcnew System::EventHandler(this, &MyForm1::buttonProgram_Click);
			// 
			// buttonSubjects
			// 
			this->buttonSubjects->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->buttonSubjects->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonSubjects->FlatAppearance->BorderSize = 0;
			this->buttonSubjects->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSubjects->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonSubjects->Location = System::Drawing::Point(0, 84);
			this->buttonSubjects->Name = L"buttonSubjects";
			this->buttonSubjects->Size = System::Drawing::Size(111, 40);
			this->buttonSubjects->TabIndex = 2;
			this->buttonSubjects->Text = L"Subjects";
			this->buttonSubjects->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonSubjects->UseMnemonic = false;
			this->buttonSubjects->UseVisualStyleBackColor = false;
			this->buttonSubjects->Click += gcnew System::EventHandler(this, &MyForm1::buttonSubjects_Click);
			// 
			// buttonInfo
			// 
			this->buttonInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->buttonInfo->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonInfo->FlatAppearance->BorderSize = 0;
			this->buttonInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonInfo->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonInfo->Location = System::Drawing::Point(0, 44);
			this->buttonInfo->Name = L"buttonInfo";
			this->buttonInfo->Size = System::Drawing::Size(111, 40);
			this->buttonInfo->TabIndex = 1;
			this->buttonInfo->Text = L"Information";
			this->buttonInfo->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonInfo->UseMnemonic = false;
			this->buttonInfo->UseVisualStyleBackColor = false;
			this->buttonInfo->Click += gcnew System::EventHandler(this, &MyForm1::buttonInfo_Click);
			// 
			// panelInfo
			// 
			this->panelInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->panelInfo->Controls->Add(this->buttonMenu);
			this->panelInfo->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelInfo->Location = System::Drawing::Point(0, 0);
			this->panelInfo->Name = L"panelInfo";
			this->panelInfo->Size = System::Drawing::Size(111, 44);
			this->panelInfo->TabIndex = 0;
			// 
			// buttonMenu
			// 
			this->buttonMenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->buttonMenu->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonMenu->FlatAppearance->BorderSize = 0;
			this->buttonMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMenu->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonMenu->Location = System::Drawing::Point(0, 0);
			this->buttonMenu->Name = L"buttonMenu";
			this->buttonMenu->Size = System::Drawing::Size(111, 44);
			this->buttonMenu->TabIndex = 2;
			this->buttonMenu->Text = L"Menu";
			this->buttonMenu->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonMenu->UseMnemonic = false;
			this->buttonMenu->UseVisualStyleBackColor = false;
			this->buttonMenu->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click_1);
			// 
			// panelDesktop
			// 
			this->panelDesktop->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelDesktop->Location = System::Drawing::Point(111, 0);
			this->panelDesktop->Margin = System::Windows::Forms::Padding(0);
			this->panelDesktop->Name = L"panelDesktop";
			this->panelDesktop->Size = System::Drawing::Size(465, 324);
			this->panelDesktop->TabIndex = 10;
			this->panelDesktop->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm1::panelDesktop_Paint);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 324);
			this->Controls->Add(this->panelDesktop);
			this->Controls->Add(this->panelMenu);
			this->Name = L"MyForm1";
			this->Text = L"Form2";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->panelMenu->ResumeLayout(false);
			this->panelInfo->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e) {
		Subjects^ subjectsForm = gcnew Subjects();
		OpenChildForm(subjectsForm);
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonInfo_Click(System::Object^ sender, System::EventArgs^ e) {
		Info^ infoForm = gcnew Info();
		OpenChildForm(infoForm);
	}
private: System::Void panelDesktop_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void buttonProgram_Click(System::Object^ sender, System::EventArgs^ e) {
	Zus^ zusForm = gcnew Zus();
	OpenChildForm(zusForm);
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	MyMenu^ menuForm = gcnew MyMenu();
	OpenChildForm(menuForm);
}
private: System::Void buttonLibrary_Click(System::Object^ sender, System::EventArgs^ e) {
	Library^ libForm = gcnew Library();
	OpenChildForm(libForm);
}
private: System::Void buttonScience_Click(System::Object^ sender, System::EventArgs^ e) {
	Science^ scForm = gcnew Science();
	OpenChildForm(scForm);
}
private: System::Void buttonPractice_Click(System::Object^ sender, System::EventArgs^ e) {
	Practice^ prForm = gcnew Practice();
	OpenChildForm(prForm);
}
private: System::Void buttonDiploma_Click(System::Object^ sender, System::EventArgs^ e) {
	Diploma^ dpForm = gcnew Diploma();
	OpenChildForm(dpForm);
}
private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}

