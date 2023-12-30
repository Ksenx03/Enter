#pragma once

#include <fstream>

namespace Enter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для My2024
	/// </summary>
	public ref class My2024 : public System::Windows::Forms::Form
	{
	public:
		My2024(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->checkedListBox4->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &My2024::checkedListBox_ItemCheck);
			this->checkedListBox5->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &My2024::checkedListBox_ItemCheck);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~My2024()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox4;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox5;




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkedListBox4 = (gcnew System::Windows::Forms::CheckedListBox());
			this->checkedListBox5 = (gcnew System::Windows::Forms::CheckedListBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(55, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Oplata";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(213, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Deklaracja";
			// 
			// checkedListBox4
			// 
			this->checkedListBox4->FormattingEnabled = true;
			this->checkedListBox4->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Styczen", L"Luty ", L"Marzec ", L"Kwiecien",
					L"Maj ", L"Czerwiec ", L"Lipiec ", L"Sierpien ", L"Wrzesien ", L"Pazdziernik ", L"Listopad ", L"Grudzien "
			});
			this->checkedListBox4->Location = System::Drawing::Point(6, 46);
			this->checkedListBox4->Name = L"checkedListBox4";
			this->checkedListBox4->Size = System::Drawing::Size(155, 214);
			this->checkedListBox4->TabIndex = 2;
			// 
			// checkedListBox5
			// 
			this->checkedListBox5->FormattingEnabled = true;
			this->checkedListBox5->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Styczen", L"Luty ", L"Marzec ", L"Kwiecien ",
					L"Maj ", L"Czerwiec ", L"Lipiec ", L"Sierpien ", L"Wrzesien ", L"Pazdziernik ", L"Listopad ", L"Grudzien "
			});
			this->checkedListBox5->Location = System::Drawing::Point(167, 46);
			this->checkedListBox5->Name = L"checkedListBox5";
			this->checkedListBox5->Size = System::Drawing::Size(155, 214);
			this->checkedListBox5->TabIndex = 3;
			// 
			// My2024
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightBlue;
			this->ClientSize = System::Drawing::Size(329, 272);
			this->Controls->Add(this->checkedListBox5);
			this->Controls->Add(this->checkedListBox4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"My2024";
			this->Text = L"My2024";
			this->Load += gcnew System::EventHandler(this, &My2024::My2024_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void My2024_Load(System::Object^ sender, System::EventArgs^ e) {
			LoadCheckedListBoxState(this->checkedListBox4, "checkedListBox4_state.txt");
			LoadCheckedListBoxState(this->checkedListBox5, "checkedListBox5_state.txt");
		}

		System::Void checkedListBox_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {
			CheckedListBox^ checkedListBox = safe_cast<CheckedListBox^>(sender);
			String^ fileName = (checkedListBox == this->checkedListBox4) ? "checkedListBox4_state.txt" : "checkedListBox5_state.txt";
			// Добавить задержку для обновления состояния элемента перед сохранением
			this->BeginInvoke(gcnew Action<CheckedListBox^, String^>(SaveCheckedListBoxState), checkedListBox, fileName);
		}

		// Функции сохранения и загрузки
		static void SaveCheckedListBoxState(CheckedListBox^ checkedListBox, String^ fileName) {
			StreamWriter^ sw = gcnew StreamWriter(fileName);
			for (int i = 0; i < checkedListBox->Items->Count; i++) {
				sw->WriteLine(checkedListBox->GetItemChecked(i) ? "1" : "0");
			}
			sw->Close();
		}

		void LoadCheckedListBoxState(CheckedListBox^ checkedListBox, String^ fileName) {
			if (File::Exists(fileName)) {
				StreamReader^ sr = gcnew StreamReader(fileName);
				String^ line;
				int index = 0;
				while ((line = sr->ReadLine()) != nullptr && index < checkedListBox->Items->Count) {
					checkedListBox->SetItemChecked(index, line == "1");
					index++;
				}
				sr->Close();
			}
		}
	};
}
