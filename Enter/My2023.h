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

    public ref class My2023 : public System::Windows::Forms::Form
    {
    public:
        My2023(void)
        {
            InitializeComponent();

            // Добавьте обработчики событий
            this->checkedListBox2->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &My2023::checkedListBox_ItemCheck);
            this->checkedListBox3->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &My2023::checkedListBox_ItemCheck);
        }

    protected:
        ~My2023()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::CheckedListBox^ checkedListBox2;
    private: System::Windows::Forms::CheckedListBox^ checkedListBox3;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->checkedListBox2 = (gcnew System::Windows::Forms::CheckedListBox());
            this->checkedListBox3 = (gcnew System::Windows::Forms::CheckedListBox());
            this->SuspendLayout();
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(55, 13);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(38, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Oplata";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(213, 13);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(58, 13);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Deklaracja";
            // 
            // checkedListBox2
            // 
            this->checkedListBox2->FormattingEnabled = true;
            this->checkedListBox2->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
                L"Styczen", L"Luty ", L"Marzec ", L"Kwiecien",
                    L"Maj ", L"Czerwiec ", L"Lipiec ", L"Sierpien ", L"Wrzesien ", L"Pazdziernik ", L"Listopad ", L"Grudzien "
            });
            this->checkedListBox2->Location = System::Drawing::Point(6, 46);
            this->checkedListBox2->Name = L"checkedListBox2";
            this->checkedListBox2->Size = System::Drawing::Size(155, 214);
            this->checkedListBox2->TabIndex = 4;
            // 
            // checkedListBox3
            // 
            this->checkedListBox3->FormattingEnabled = true;
            this->checkedListBox3->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
                L"Styczen", L"Luty ", L"Marzec ", L"Kwiecien ",
                    L"Maj ", L"Czerwiec ", L"Lipiec ", L"Sierpien ", L"Wrzesien ", L"Pazdziernik ", L"Listopad ", L"Grudzien "
            });
            this->checkedListBox3->Location = System::Drawing::Point(167, 46);
            this->checkedListBox3->Name = L"checkedListBox3";
            this->checkedListBox3->Size = System::Drawing::Size(155, 214);
            this->checkedListBox3->TabIndex = 5;
            // 
            // My2023
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::PowderBlue;
            this->ClientSize = System::Drawing::Size(329, 272);
            this->Controls->Add(this->checkedListBox3);
            this->Controls->Add(this->checkedListBox2);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Name = L"My2023";
            this->Text = L"My2023";
            this->Load += gcnew System::EventHandler(this, &My2023::My2023_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void My2023_Load(System::Object^ sender, System::EventArgs^ e) {
            LoadCheckedListBoxState(this->checkedListBox2, "checkedListBox2_state.txt");
            LoadCheckedListBoxState(this->checkedListBox3, "checkedListBox3_state.txt");
        }

        System::Void checkedListBox_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {
            CheckedListBox^ checkedListBox = safe_cast<CheckedListBox^>(sender);
            String^ fileName = (checkedListBox == this->checkedListBox2) ? "checkedListBox2_state.txt" : "checkedListBox3_state.txt";
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