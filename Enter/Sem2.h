#pragma once

namespace Enter {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Sem2
	/// </summary>
	public ref class Sem2 : public System::Windows::Forms::Form
	{
	public:
		Sem2(void)
		{
			InitializeComponent();
			InitializeDataGridView();
			LoadDataFromFile();
			CalculateAverageGrade();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Sem2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonSave2;
	protected:

	private: System::Windows::Forms::Panel^ panelSem2;
	private: System::Windows::Forms::Panel^ panelSem2Buttons;
	private: System::Windows::Forms::Button^ buttonClear2;

	private: System::Windows::Forms::Button^ buttonCount2;
	private: System::Windows::Forms::DataGridView^ dataGridView2;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		void InitializeDataGridView()
		{
			dataGridView2->AutoGenerateColumns = false;
			dataGridView2->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			DataGridViewTextBoxColumn^ subjectColumn = gcnew DataGridViewTextBoxColumn();
			subjectColumn->Name = "Subject";
			subjectColumn->HeaderText = "Предмет";
			dataGridView2->Columns->Add(subjectColumn);

			array<String^>^ subjects = { "Fizyka",
				"Metody numeryczne i symulacja",
				"Programowanie strukturalne i obiektowe",
				"Rownanie rozniczkowe i przeksztalcania calkowite",
				"Teoria obwodow",
				"Jezyk obcy",
				"Dodatkowy przedmiot",
				"Srednia ocena"
			};

			dataGridView2->RowCount = subjects->Length;


			for (int i = 0; i < subjects->Length; ++i)
			{
				dataGridView2->Rows[i]->Cells["Subject"]->Value = subjects[i];
			}

			DataGridViewTextBoxColumn^ typeColumn = gcnew DataGridViewTextBoxColumn();
			typeColumn->Name = "Type";
			typeColumn->HeaderText = "Тип";
			dataGridView2->Columns->Add(typeColumn);

			array<String^>^ types = { "E",
				"E",
				"Z",
				"E",
				"Z",
				"Z",
				"Z",
				"Z",
			};

			for (int i = 0; i < types->Length; ++i)
			{
				dataGridView2->Rows[i]->Cells["Type"]->Value = types[i];
			}

			dataGridView2->Columns["Subject"]->ReadOnly = true;
			dataGridView2->Columns["Type"]->ReadOnly = true;


			DataGridViewTextBoxColumn^ gradeColumn = gcnew DataGridViewTextBoxColumn();
			gradeColumn->Name = "Grade";
			gradeColumn->HeaderText = "Оценка";
			gradeColumn->ValueType = Object::typeid;
			dataGridView2->Columns->Add(gradeColumn);

			dataGridView2->RowHeadersVisible = false;

			// Добавление DataGridView в panelGrid
			panelSem2->Controls->Add(dataGridView2);

			subjectColumn->Width = 150;
			typeColumn->Width = 70;
			gradeColumn->Width = 70;

		}

		void LoadDataFromFile() {
			if (File::Exists("grades2.txt")) {
				array<String^>^ lines = File::ReadAllLines("grades2.txt");
				int rowCount = Math::Min(lines->Length, dataGridView2->Rows->Count);

				for (int i = 0; i < rowCount; i++) {
					dataGridView2->Rows[i]->Cells["Grade"]->Value = lines[i];
				}
			}
		}

		void CalculateAverageGrade() {
			double sum = 0.0;
			double count = 0.0;

			for (int i = 0; i < dataGridView2->Rows->Count - 1; ++i) {
				if (dataGridView2->Rows[i]->Cells[2]->Value != nullptr) {
					String^ value = dataGridView2->Rows[i]->Cells[2]->Value->ToString();
					double number;

					if (Double::TryParse(value, number)) {
						sum += number;
						count++;
					}
				}
			}

			if (count > 0) {
				double average = sum / count;
				dataGridView2->Rows[dataGridView2->Rows->Count - 1]->Cells[2]->Value = average.ToString("F2");
			}
			else {
				dataGridView2->Rows[dataGridView2->Rows->Count - 1]->Cells[2]->Value = "Нет данных";
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonSave2 = (gcnew System::Windows::Forms::Button());
			this->panelSem2 = (gcnew System::Windows::Forms::Panel());
			this->panelSem2Buttons = (gcnew System::Windows::Forms::Panel());
			this->buttonCount2 = (gcnew System::Windows::Forms::Button());
			this->buttonClear2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->panelSem2->SuspendLayout();
			this->panelSem2Buttons->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonSave2
			// 
			this->buttonSave2->BackColor = System::Drawing::Color::MediumAquamarine;
			this->buttonSave2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonSave2->Location = System::Drawing::Point(0, 195);
			this->buttonSave2->Name = L"buttonSave2";
			this->buttonSave2->Size = System::Drawing::Size(106, 37);
			this->buttonSave2->TabIndex = 0;
			this->buttonSave2->Text = L"Сохранить изменения";
			this->buttonSave2->UseVisualStyleBackColor = false;
			this->buttonSave2->Click += gcnew System::EventHandler(this, &Sem2::buttonSave2_Click);

			// 
			// panelSem2
			// 
			this->panelSem2->BackColor = System::Drawing::Color::Aquamarine;
			this->panelSem2->Controls->Add(this->dataGridView2);
			this->panelSem2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSem2->Location = System::Drawing::Point(0, 0);
			this->panelSem2->Name = L"panelSem2";
			this->panelSem2->Size = System::Drawing::Size(274, 232);
			this->panelSem2->TabIndex = 1;
			// 
			// panelSem2Buttons
			// 
			this->panelSem2Buttons->BackColor = System::Drawing::Color::Aquamarine;
			this->panelSem2Buttons->Controls->Add(this->buttonClear2);
			this->panelSem2Buttons->Controls->Add(this->buttonCount2);
			this->panelSem2Buttons->Controls->Add(this->buttonSave2);
			this->panelSem2Buttons->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelSem2Buttons->Location = System::Drawing::Point(274, 0);
			this->panelSem2Buttons->Name = L"panelSem2Buttons";
			this->panelSem2Buttons->Size = System::Drawing::Size(106, 232);
			this->panelSem2Buttons->TabIndex = 2;
			// 
			// buttonCount2
			// 
			this->buttonCount2->BackColor = System::Drawing::Color::MediumAquamarine;
			this->buttonCount2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonCount2->Location = System::Drawing::Point(0, 158);
			this->buttonCount2->Name = L"buttonCount2";
			this->buttonCount2->Size = System::Drawing::Size(106, 37);
			this->buttonCount2->TabIndex = 1;
			this->buttonCount2->Text = L"Рассчитать среднее";
			this->buttonCount2->UseVisualStyleBackColor = false;
			// 
			// buttonClear2
			// 
			this->buttonClear2->BackColor = System::Drawing::Color::MediumAquamarine;
			this->buttonClear2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonClear2->Location = System::Drawing::Point(0, 121);
			this->buttonClear2->Name = L"buttonClear2";
			this->buttonClear2->Size = System::Drawing::Size(106, 37);
			this->buttonClear2->TabIndex = 2;
			this->buttonClear2->Text = L"Очистить\r\n";
			this->buttonClear2->UseVisualStyleBackColor = false;
			// 
			// dataGridView2
			// 
			this->dataGridView2->BackgroundColor = System::Drawing::Color::Aquamarine;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(274, 232);
			this->dataGridView2->TabIndex = 0;
			// 
			// Sem2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(380, 232);
			this->Controls->Add(this->panelSem2Buttons);
			this->Controls->Add(this->panelSem2);
			this->Name = L"Sem2";
			this->Text = L"Sem2";
			this->Load += gcnew System::EventHandler(this, &Sem2::Sem2_Load);
			this->panelSem2->ResumeLayout(false);
			this->panelSem2Buttons->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Sem2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonSave2_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamWriter^ sw = gcnew StreamWriter("grades2.txt");

		try {
			for (int i = 0; i < dataGridView2->Rows->Count; i++) {
				String^ grade = dataGridView2->Rows[i]->Cells["Grade"]->Value ? dataGridView2->Rows[i]->Cells["Grade"]->Value->ToString() : "";

				// Запись значения 'grade' в файл
				sw->WriteLine(grade);
			}

			// Показать сообщение об успешном сохранении
			MessageBox::Show("Сохранено успешно!");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка при сохранении: " + ex->Message);
		}
		finally {
			if (sw != nullptr) {
				sw->Close();
			}
		}
	}


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	CalculateAverageGrade();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	for each (DataGridViewRow ^ row in dataGridView2->Rows) {
		row->Cells["Grade"]->Value = ""; // Установка пустого значения для третьего столбца
	}

	// Очистка текстового файла
	System::IO::File::WriteAllText("data.txt", "");
	}
};
}

