#pragma once

#include <vcclr.h>
#include <cliext/vector>



namespace Enter {

    using namespace System;
    using namespace System::Configuration;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Data;
    using namespace System::IO;

    public ref class Info : public System::Windows::Forms::Form
    {
    public:
        Info(void)
        {
            InitializeComponent();
            InitializeDataGridView();
        }

    protected:
        ~Info()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridView;
        DataSet^ dataSet;
        System::String^ tempImagePath;

    private:

        System::Drawing::Image^ currentImage;
        System::Windows::Forms::Panel^ panel3;
        System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Button^ buttonImageSave;
    private: System::Windows::Forms::Button^ buttonImage;
    private: System::Windows::Forms::PictureBox^ pictureBox1;

           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Info::typeid));
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->buttonImageSave = (gcnew System::Windows::Forms::Button());
            this->buttonImage = (gcnew System::Windows::Forms::Button());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->panel3->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // panel3
            // 
            this->panel3->BackColor = System::Drawing::Color::CornflowerBlue;
            this->panel3->Controls->Add(this->pictureBox1);
            this->panel3->Controls->Add(this->buttonImageSave);
            this->panel3->Controls->Add(this->buttonImage);
            this->panel3->Controls->Add(this->dataGridView1);
            this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel3->Location = System::Drawing::Point(0, 0);
            this->panel3->Margin = System::Windows::Forms::Padding(0);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(449, 285);
            this->panel3->TabIndex = 3;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(230, 23);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(200, 180);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 3;
            this->pictureBox1->TabStop = false;
            // 
            // buttonImageSave
            // 
            this->buttonImageSave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->buttonImageSave->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)));
            this->buttonImageSave->Location = System::Drawing::Point(354, 247);
            this->buttonImageSave->Name = L"buttonImageSave";
            this->buttonImageSave->Size = System::Drawing::Size(83, 26);
            this->buttonImageSave->TabIndex = 2;
            this->buttonImageSave->Text = L"Save";
            this->buttonImageSave->UseVisualStyleBackColor = false;
            this->buttonImageSave->Click += gcnew System::EventHandler(this, &Info::buttonImageSave_Click);
            // 
            // buttonImage
            // 
            this->buttonImage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->buttonImage->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)));
            this->buttonImage->Location = System::Drawing::Point(230, 247);
            this->buttonImage->Name = L"buttonImage";
            this->buttonImage->Size = System::Drawing::Size(83, 26);
            this->buttonImage->TabIndex = 1;
            this->buttonImage->Text = L"Dodac zdjecie";
            this->buttonImage->UseVisualStyleBackColor = false;
            this->buttonImage->Click += gcnew System::EventHandler(this, &Info::buttonImage_Click);
            // 
            // dataGridView1
            // 
            this->dataGridView1->BackgroundColor = System::Drawing::Color::CornflowerBlue;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Left;
            this->dataGridView1->Location = System::Drawing::Point(0, 0);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(214, 285);
            this->dataGridView1->TabIndex = 0;
            // 
            // Info
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LavenderBlush;
            this->ClientSize = System::Drawing::Size(449, 285);
            this->Controls->Add(this->panel3);
            this->Name = L"Info";
            this->Text = L"Info";
            this->Load += gcnew System::EventHandler(this, &Info::Info_Load);
            this->panel3->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);

        }

        void InitializeDataGridView()
        {
            dataSet = gcnew DataSet("MyDataSet");
            dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            DataTable^ dataTable = gcnew DataTable("MyTable");

            dataTable->Columns->Add("Parameter", String::typeid);
            dataTable->Columns->Add("Value", String::typeid);

            dataSet->Tables->Add(dataTable);

            array<String^>^ parameters = { "Imie", "Nazwisko", "Kierunek", "Rok", "Studia", "Numer albumu", "PESEL", "Mail", "Telefon" };
            array<String^>^ values = { "Kseniya", "Barysava", "Automatyka i Robotyka", "I", "Stacjonarne", "159132", "01210313780", "kseniya.barysava@student.put.poznan.pl", "505719305" };

            for (int i = 0; i < parameters->Length; i++)
            {
                DataRow^ row = dataTable->NewRow();
                row["Parameter"] = parameters[i];
                row["Value"] = values[i];
                dataTable->Rows->Add(row);
            }

            dataGridView1->DataSource = dataSet->Tables["MyTable"];
            dataGridView1->Columns["Parameter"]->ReadOnly = true;
            dataGridView1->RowHeadersVisible = false;
        }

#pragma endregion

    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void dataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
    private: System::Void Info_Load(System::Object^ sender, System::EventArgs^ e) {
      /*  String^ imagePath = ConfigurationManager::AppSettings["ImagePath"];
        if (System::IO::File::Exists(imagePath)) {
            pictureBox1->Image = System::Drawing::Image::FromFile(imagePath);
        }*/
    }
    private: System::Void buttonImage_Click(System::Object^ sender, System::EventArgs^ e) {
        OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
        openFileDialog->InitialDirectory = "c:\\"; // или другой начальный путь
        openFileDialog->Filter = "Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG|All files (*.*)|*.*";
        openFileDialog->RestoreDirectory = true;

        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            // Загрузка изображения
            System::Drawing::Image^ currentImage = System::Drawing::Image::FromFile(openFileDialog->FileName);
            pictureBox1->Image = currentImage;

            // Сохранение пути к изображению во временную переменную
            this->tempImagePath = openFileDialog->FileName;
        }
    }
private: System::Void buttonImageSave_Click(System::Object^ sender, System::EventArgs^ e) {
    //if (!String::IsNullOrEmpty(this->tempImagePath)) {
    //    try {
    //        // Получение текущей конфигурации
    //        Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

    //        // Установка значения настройки
    //        config->AppSettings->Settings["ImagePath"]->Value = this->tempImagePath;

    //        // Сохранение изменений
    //        config->Save(ConfigurationSaveMode::Modified);
    //        ConfigurationManager::RefreshSection("appSettings");

    //        // Отображение сообщения об успешном сохранении
    //        MessageBox::Show("Сохранено успешно!");
    //    }
    //    catch (Exception^ ex) {
    //        MessageBox::Show("Ошибка при сохранении: " + ex->Message);
    //    }
    //}
    //else {
    //    MessageBox::Show("Изображение не выбрано!");
    //}
}
};
}
