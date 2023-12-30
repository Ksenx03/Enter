#pragma once

#include "My2023.h"
#include "My2024.h"
#include "My2025.h"
#include "My2026.h"

namespace Enter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Program
	/// </summary>
	public ref class Zus : public System::Windows::Forms::Form
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
			childForm->Size = panelZus->Size;

			// ”станавливаем форме свойство FormBorderStyle в None
			childForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;

			childForm->Dock = System::Windows::Forms::DockStyle::Fill;
			panelZus->Controls->Add(childForm);
			childForm->Show();
		}
	public:
		Zus(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			currentForm = nullptr;

			/*Zus^ zusForm = gcnew Zus();
			OpenChildForm(zusForm);*/
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Zus()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button2026;

	private: System::Windows::Forms::Button^ button2025;

	private: System::Windows::Forms::Button^ button2024;

	private: System::Windows::Forms::Button^ button2023;

	private: System::Windows::Forms::Panel^ panelZus;



	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2026 = (gcnew System::Windows::Forms::Button());
			this->button2025 = (gcnew System::Windows::Forms::Button());
			this->button2024 = (gcnew System::Windows::Forms::Button());
			this->button2023 = (gcnew System::Windows::Forms::Button());
			this->panelZus = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel1->Controls->Add(this->button2026);
			this->panel1->Controls->Add(this->button2025);
			this->panel1->Controls->Add(this->button2024);
			this->panel1->Controls->Add(this->button2023);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(139, 311);
			this->panel1->TabIndex = 1;
			// 
			// button2026
			// 
			this->button2026->BackColor = System::Drawing::Color::LightSkyBlue;
			this->button2026->Dock = System::Windows::Forms::DockStyle::Top;
			this->button2026->Location = System::Drawing::Point(0, 111);
			this->button2026->Name = L"button2026";
			this->button2026->Size = System::Drawing::Size(139, 37);
			this->button2026->TabIndex = 3;
			this->button2026->Text = L"2026";
			this->button2026->UseVisualStyleBackColor = false;
			this->button2026->Click += gcnew System::EventHandler(this, &Zus::button2026_Click);
			// 
			// button2025
			// 
			this->button2025->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button2025->Dock = System::Windows::Forms::DockStyle::Top;
			this->button2025->Location = System::Drawing::Point(0, 74);
			this->button2025->Name = L"button2025";
			this->button2025->Size = System::Drawing::Size(139, 37);
			this->button2025->TabIndex = 2;
			this->button2025->Text = L"2025";
			this->button2025->UseVisualStyleBackColor = false;
			this->button2025->Click += gcnew System::EventHandler(this, &Zus::button2025_Click);
			// 
			// button2024
			// 
			this->button2024->BackColor = System::Drawing::Color::LightBlue;
			this->button2024->Dock = System::Windows::Forms::DockStyle::Top;
			this->button2024->Location = System::Drawing::Point(0, 37);
			this->button2024->Name = L"button2024";
			this->button2024->Size = System::Drawing::Size(139, 37);
			this->button2024->TabIndex = 1;
			this->button2024->Text = L"2024";
			this->button2024->UseVisualStyleBackColor = false;
			this->button2024->Click += gcnew System::EventHandler(this, &Zus::button2_Click);
			// 
			// button2023
			// 
			this->button2023->BackColor = System::Drawing::Color::PowderBlue;
			this->button2023->Dock = System::Windows::Forms::DockStyle::Top;
			this->button2023->Location = System::Drawing::Point(0, 0);
			this->button2023->Name = L"button2023";
			this->button2023->Size = System::Drawing::Size(139, 37);
			this->button2023->TabIndex = 0;
			this->button2023->Text = L"2023";
			this->button2023->UseVisualStyleBackColor = false;
			this->button2023->Click += gcnew System::EventHandler(this, &Zus::button2023_Click);
			// 
			// panelZus
			// 
			this->panelZus->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panelZus->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelZus->Location = System::Drawing::Point(139, 0);
			this->panelZus->Name = L"panelZus";
			this->panelZus->Size = System::Drawing::Size(345, 311);
			this->panelZus->TabIndex = 2;
			// 
			// Zus
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 311);
			this->Controls->Add(this->panelZus);
			this->Controls->Add(this->panel1);
			this->Name = L"Zus";
			this->Text = L"ZUS";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void button2023_Click(System::Object^ sender, System::EventArgs^ e) {
	My2023^ my2023Form = gcnew My2023();
	OpenChildForm(my2023Form);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	My2024^ my2024Form = gcnew My2024();
	OpenChildForm(my2024Form);
}
private: System::Void button2025_Click(System::Object^ sender, System::EventArgs^ e) {
	My2025^ my2025Form = gcnew My2025();
	OpenChildForm(my2025Form);
}
private: System::Void button2026_Click(System::Object^ sender, System::EventArgs^ e) {
	My2026^ my2026Form = gcnew My2026();
	OpenChildForm(my2026Form);
}
};
}
