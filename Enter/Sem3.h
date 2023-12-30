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
	/// Сводка для Sem3
	/// </summary>
	public ref class Sem3 : public System::Windows::Forms::Form
	{
	public:
		Sem3(void)
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
		~Sem3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelSem3;
	private: System::Windows::Forms::Panel^ panelSem3Buttons;
	private: System::Windows::Forms::Button^ buttonSave3;
	private: System::Windows::Forms::Button^ buttonClear3;

	private: System::Windows::Forms::Button^ buttonCount3;
	private: System::Windows::Forms::DataGridView^ dataGridView3;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		void InitializeDataGridView()
		{
			dataGridView3->AutoGenerateColumns = false;
			dataGridView3->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			DataGridViewTextBoxColumn^ subjectColumn = gcnew DataGridViewTextBoxColumn();
			subjectColumn->Name = "Subject";
			subjectColumn->HeaderText = "Предмет";
			dataGridView3->Columns->Add(subjectColumn);

			array<String^>^ subjects = { "Mechanika i wytrzymalosc materialow",
				"Podstawy automatyki",
				"Podstawy elektroniki",
				"Podstawy robotyki",
				"Teoria i przetwarzanie sygnalow",
				"Jezyk obcy",
				"Dodatkowy przedmiot",
				"Srednia ocena"
			};

			dataGridView3->RowCount = subjects->Length;


			for (int i = 0; i < subjects->Length; ++i)
			{
				dataGridView3->Rows[i]->Cells["Subject"]->Value = subjects[i];
			}

			DataGridViewTextBoxColumn^ typeColumn = gcnew DataGridViewTextBoxColumn();
			typeColumn->Name = "Type";
			typeColumn->HeaderText = "Тип";
			dataGridView3->Columns->Add(typeColumn);

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
				dataGridView3->Rows[i]->Cells["Type"]->Value = types[i];
			}

			dataGridView3->Columns["Subject"]->ReadOnly = true;
			dataGridView3->Columns["Type"]->ReadOnly = true;


			DataGridViewTextBoxColumn^ gradeColumn = gcnew DataGridViewTextBoxColumn();
			gradeColumn->Name = "Grade";
			gradeColumn->HeaderText = "Оценка";
			gradeColumn->ValueType = Object::typeid;
			dataGridView3->Columns->Add(gradeColumn);

			dataGridView3->RowHeadersVisible = false;

			// Добавление DataGridView в panelGrid
			panelSem3->Controls->Add(dataGridView3);

			subjectColumn->Width = 150;
			typeColumn->Width = 70;
			gradeColumn->Width = 70;

		}

		void LoadDataFromFile() {
			if (File::Exists("grades3.txt")) {
				array<String^>^ lines = File::ReadAllLines("grades3.txt");
				int rowCount = Math::Min(lines->Length, dataGridView3->Rows->Count);

				for (int i = 0; i < rowCount; i++) {
					dataGridView3->Rows[i]->Cells["Grade"]->Value = lines[i];
				}
			}
		}

		void CalculateAverageGrade() {
			double sum = 0.0;
			double count = 0.0;

			for (int i = 0; i < dataGridView3->Rows->Count - 1; ++i) {
				if (dataGridView3->Rows[i]->Cells[2]->Value != nullptr) {
					String^ value = dataGridView3->Rows[i]->Cells[2]->Value->ToString();
					double number;

					if (Double::TryParse(value, number)) {
						sum += number;
						count++;
					}
				}
			}

			if (count > 0) {
				double average = sum / count;
				dataGridView3->Rows[dataGridView3->Rows->Count - 1]->Cells[2]->Value = average.ToString("F2");
			}
			else {
				dataGridView3->Rows[dataGridView3->Rows->Count - 1]->Cells[2]->Value = "Нет данных";
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelSem3 = (gcnew System::Windows::Forms::Panel());
			this->panelSem3Buttons = (gcnew System::Windows::Forms::Panel());
			this->buttonSave3 = (gcnew System::Windows::Forms::Button());
			this->buttonCount3 = (gcnew System::Windows::Forms::Button());
			this->buttonClear3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->panelSem3->SuspendLayout();
			this->panelSem3Buttons->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->SuspendLayout();
			// 
			// panelSem3
			// 
			this->panelSem3->Controls->Add(this->dataGridView3);
			this->panelSem3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSem3->Location = System::Drawing::Point(0, 0);
			this->panelSem3->Name = L"panelSem3";
			this->panelSem3->Size = System::Drawing::Size(274, 232);
			this->panelSem3->TabIndex = 0;
			// 
			// panelSem3Buttons
			// 
			this->panelSem3Buttons->Controls->Add(this->buttonClear3);
			this->panelSem3Buttons->Controls->Add(this->buttonCount3);
			this->panelSem3Buttons->Controls->Add(this->buttonSave3);
			this->panelSem3Buttons->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelSem3Buttons->Location = System::Drawing::Point(274, 0);
			this->panelSem3Buttons->Name = L"panelSem3Buttons";
			this->panelSem3Buttons->Size = System::Drawing::Size(106, 232);
			this->panelSem3Buttons->TabIndex = 1;
			// 
			// buttonSave3
			// 
			this->buttonSave3->BackColor = System::Drawing::Color::Aquamarine;
			this->buttonSave3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonSave3->Location = System::Drawing::Point(0, 195);
			this->buttonSave3->Name = L"buttonSave3";
			this->buttonSave3->Size = System::Drawing::Size(106, 37);
			this->buttonSave3->TabIndex = 0;
			this->buttonSave3->Text = L"Сохранить изменения";
			this->buttonSave3->UseVisualStyleBackColor = false;
			this->buttonSave3->Click += gcnew System::EventHandler(this, &Sem3::buttonSave3_Click);
			// 
			// buttonCount3
			// 
			this->buttonCount3->BackColor = System::Drawing::Color::Aquamarine;
			this->buttonCount3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonCount3->Location = System::Drawing::Point(0, 158);
			this->buttonCount3->Name = L"buttonCount3";
			this->buttonCount3->Size = System::Drawing::Size(106, 37);
			this->buttonCount3->TabIndex = 1;
			this->buttonCount3->Text = L"Рассчитать среднее";
			this->buttonCount3->UseVisualStyleBackColor = false;
			// 
			// buttonClear3
			// 
			this->buttonClear3->BackColor = System::Drawing::Color::Aquamarine;
			this->buttonClear3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonClear3->Location = System::Drawing::Point(0, 121);
			this->buttonClear3->Name = L"buttonClear3";
			this->buttonClear3->Size = System::Drawing::Size(106, 37);
			this->buttonClear3->TabIndex = 2;
			this->buttonClear3->Text = L"Очистить";
			this->buttonClear3->UseVisualStyleBackColor = false;
			// 
			// dataGridView3
			// 
			this->dataGridView3->BackgroundColor = System::Drawing::Color::Turquoise;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView3->Location = System::Drawing::Point(0, 0);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(274, 232);
			this->dataGridView3->TabIndex = 0;
			// 
			// Sem3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Turquoise;
			this->ClientSize = System::Drawing::Size(380, 232);
			this->Controls->Add(this->panelSem3Buttons);
			this->Controls->Add(this->panelSem3);
			this->Name = L"Sem3";
			this->Text = L"Sem3";
			this->panelSem3->ResumeLayout(false);
			this->panelSem3Buttons->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonSave3_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamWriter^ sw = gcnew StreamWriter("grades3.txt");

		try {
			for (int i = 0; i < dataGridView3->Rows->Count; i++) {
				String^ grade = dataGridView3->Rows[i]->Cells["Grade"]->Value ? dataGridView3->Rows[i]->Cells["Grade"]->Value->ToString() : "";

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
	for each (DataGridViewRow ^ row in dataGridView3->Rows) {
		row->Cells["Grade"]->Value = ""; // Установка пустого значения для третьего столбца
	}

	// Очистка текстового файла
	System::IO::File::WriteAllText("data.txt", "");
}
	private: System::Void Sem3_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}