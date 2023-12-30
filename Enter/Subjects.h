#pragma once

#include "Sem1.h"
#include "Sem2.h"
#include "Sem3.h"
#include "Sem4.h"
#include "Sem5.h"
#include "Sem6.h"
#include "Sem7.h"


namespace Enter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Subjects
	/// </summary>
	public ref class Subjects : public System::Windows::Forms::Form
	{
	public:
		Subjects(void)
		{
			InitializeComponent();
			currentForm = nullptr;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Subjects()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Panel^ panelSub;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	
	private:
		System::Windows::Forms::Form^ currentForm;
		// Функция для открытия указанного окна и закрытия текущего, если оно есть
		void OpenChildForm(System::Windows::Forms::Form^ childForm)
		{
			// Убедитесь, что panelSub не содержит других элементов управления
			panelSub->Controls->Clear();

			// Установите размеры и свойства формы
			childForm->TopLevel = false;
			childForm->AutoScroll = true;
			childForm->Size = panelSub->Size;
			childForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			childForm->Dock = System::Windows::Forms::DockStyle::Fill;

			// Добавьте форму к panelSub
			panelSub->Controls->Add(childForm);
			childForm->Show();
		}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->panelSub = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button21);
			this->panel1->Controls->Add(this->button11);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(88, 311);
			this->panel1->TabIndex = 0;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Cyan;
			this->button7->Dock = System::Windows::Forms::DockStyle::Top;
			this->button7->Location = System::Drawing::Point(0, 264);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(88, 44);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Semestr 7";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Subjects::button7_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::PaleTurquoise;
			this->button6->Dock = System::Windows::Forms::DockStyle::Top;
			this->button6->Location = System::Drawing::Point(0, 220);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(88, 44);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Semestr 6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Subjects::button6_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::MediumTurquoise;
			this->button5->Dock = System::Windows::Forms::DockStyle::Top;
			this->button5->Location = System::Drawing::Point(0, 176);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(88, 44);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Semestr 5";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Subjects::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button4->Dock = System::Windows::Forms::DockStyle::Top;
			this->button4->Location = System::Drawing::Point(0, 132);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(88, 44);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Semestr 4";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Subjects::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Turquoise;
			this->button3->Dock = System::Windows::Forms::DockStyle::Top;
			this->button3->Location = System::Drawing::Point(0, 88);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(88, 44);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Semestr 3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Subjects::button3_Click);
			// 
			// button21
			// 
			this->button21->BackColor = System::Drawing::Color::Aquamarine;
			this->button21->Dock = System::Windows::Forms::DockStyle::Top;
			this->button21->Location = System::Drawing::Point(0, 44);
			this->button21->Name = L"button2";
			this->button21->Size = System::Drawing::Size(88, 44);
			this->button21->TabIndex = 1;
			this->button21->Text = L"Semestr 2";
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &Subjects::button21_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::MediumAquamarine;
			this->button11->Dock = System::Windows::Forms::DockStyle::Top;
			this->button11->Location = System::Drawing::Point(0, 0);
			this->button11->Name = L"button1";
			this->button11->Size = System::Drawing::Size(88, 44);
			this->button11->TabIndex = 0;
			this->button11->Text = L"Semestr 1";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &Subjects::button11_Click);
			// 
			// panelSub
			// 
			this->panelSub->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panelSub->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelSub->Location = System::Drawing::Point(88, 0);
			this->panelSub->Name = L"panelSub";
			this->panelSub->Size = System::Drawing::Size(396, 311);
			this->panelSub->TabIndex = 1;
			// 
			// Subjects
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 311);
			this->Controls->Add(this->panelSub);
			this->Controls->Add(this->panel1);
			this->Name = L"Subjects";
			this->Text = L"Subjects";
			this->Load += gcnew System::EventHandler(this, &Subjects::Subjects_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void Subjects_Load(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		Sem1^ sem1Form = gcnew Sem1();
		OpenChildForm(sem1Form);
	}

	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
		Sem2^ sem2Form = gcnew Sem2();
		OpenChildForm(sem2Form);
	}
	
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Sem3^ sem3Form = gcnew Sem3();
		OpenChildForm(sem3Form);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Sem4^ sem4Form = gcnew Sem4();
		OpenChildForm(sem4Form);
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		Sem5^ sem5Form = gcnew Sem5();
		OpenChildForm(sem5Form);
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		Sem6^ sem6Form = gcnew Sem6();
		OpenChildForm(sem6Form);
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		Sem7^ sem7Form = gcnew Sem7();
		OpenChildForm(sem7Form);
	}
};
}
