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
	/// Сводка для My2025
	/// </summary>
	public ref class My2025 : public System::Windows::Forms::Form
	{
	public:
		My2025(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->checkedListBox6->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &My2025::checkedListBox_ItemCheck);
			this->checkedListBox7->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &My2025::checkedListBox_ItemCheck);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~My2025()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox6;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox7;

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
			this->checkedListBox6 = (gcnew System::Windows::Forms::CheckedListBox());
			this->checkedListBox7 = (gcnew System::Windows::Forms::CheckedListBox());
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
			// checkedListBox6
			// 
			this->checkedListBox6->FormattingEnabled = true;
			this->checkedListBox6->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Styczen", L"Luty ", L"Marzec ", L"Kwiecien",
					L"Maj ", L"Czerwiec ", L"Lipiec ", L"Sierpien ", L"Wrzesien ", L"Pazdziernik ", L"Listopad ", L"Grudzien "
			});
			this->checkedListBox6->Location = System::Drawing::Point(6, 46);
			this->checkedListBox6->Name = L"checkedListBox6";
			this->checkedListBox6->Size = System::Drawing::Size(155, 214);
			this->checkedListBox6->TabIndex = 2;
			// 
			// checkedListBox7
			// 
			this->checkedListBox7->FormattingEnabled = true;
			this->checkedListBox7->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Styczen", L"Luty ", L"Marzec ", L"Kwiecien",
					L"Maj ", L"Czerwiec ", L"Lipiec ", L"Sierpien ", L"Wrzesien ", L"Pazdziernik ", L"Listopad ", L"Grudzien "
			});
			this->checkedListBox7->Location = System::Drawing::Point(167, 46);
			this->checkedListBox7->Name = L"checkedListBox7";
			this->checkedListBox7->Size = System::Drawing::Size(155, 214);
			this->checkedListBox7->TabIndex = 3;
			// 
			// My2025
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(329, 272);
			this->Controls->Add(this->checkedListBox7);
			this->Controls->Add(this->checkedListBox6);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"My2025";
			this->Text = L"My2025";
			this->Load += gcnew System::EventHandler(this, &My2025::My2025_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void My2025_Load(System::Object^ sender, System::EventArgs^ e) {
			LoadCheckedListBoxState(this->checkedListBox6, "checkedListBox6_state.txt");
			LoadCheckedListBoxState(this->checkedListBox7, "checkedListBox7_state.txt");
		}

		System::Void checkedListBox_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {
			CheckedListBox^ checkedListBox = safe_cast<CheckedListBox^>(sender);
			String^ fileName = (checkedListBox == this->checkedListBox6) ? "checkedListBox6_state.txt" : "checkedListBox7_state.txt";
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

