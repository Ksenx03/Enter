#pragma once


namespace Enter {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для Sem1
	/// </summary>
	public ref class Sem1 : public System::Windows::Forms::Form
	{
	public:
		Sem1(void)
		{
			InitializeComponent();
			InitializeDataGridView();
			LoadDataFromFile();
			CalculateAverageGrade();
			//this->Show();
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Sem1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		DataGridView^ dataGridView;
	private: System::Windows::Forms::Panel^ panelGrid;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ buttonClear;


	private: System::Windows::Forms::Button^ buttonCount;



		   /// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->panelGrid = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonCount = (gcnew System::Windows::Forms::Button());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->panelGrid->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->BackgroundColor = System::Drawing::Color::MediumAquamarine;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Dock = System::Windows::Forms::DockStyle::Left;
			this->dataGridView->Location = System::Drawing::Point(0, 0);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->Size = System::Drawing::Size(274, 232);
			this->dataGridView->TabIndex = 0;
			// 
			// panelGrid
			// 
			this->panelGrid->Controls->Add(this->panel2);
			this->panelGrid->Controls->Add(this->dataGridView);
			this->panelGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelGrid->Location = System::Drawing::Point(0, 0);
			this->panelGrid->Name = L"panelGrid";
			this->panelGrid->Size = System::Drawing::Size(380, 232);
			this->panelGrid->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::MediumAquamarine;
			this->panel2->Controls->Add(this->buttonClear);
			this->panel2->Controls->Add(this->buttonCount);
			this->panel2->Controls->Add(this->buttonSave);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(274, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(106, 232);
			this->panel2->TabIndex = 2;
			// 
			// buttonClear
			// 
			this->buttonClear->BackColor = System::Drawing::Color::Aquamarine;
			this->buttonClear->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonClear->Location = System::Drawing::Point(0, 121);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(106, 37);
			this->buttonClear->TabIndex = 3;
			this->buttonClear->Text = L"Очистить";
			this->buttonClear->UseVisualStyleBackColor = false;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Sem1::button2_Click);
			// 
			// buttonCount
			// 
			this->buttonCount->BackColor = System::Drawing::Color::Aquamarine;
			this->buttonCount->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonCount->Location = System::Drawing::Point(0, 158);
			this->buttonCount->Name = L"buttonCount";
			this->buttonCount->Size = System::Drawing::Size(106, 37);
			this->buttonCount->TabIndex = 2;
			this->buttonCount->Text = L"Рассчитать средний бал";
			this->buttonCount->UseVisualStyleBackColor = false;
			this->buttonCount->Click += gcnew System::EventHandler(this, &Sem1::button1_Click);
			// 
			// buttonSave
			// 
			this->buttonSave->BackColor = System::Drawing::Color::Aquamarine;
			this->buttonSave->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonSave->Location = System::Drawing::Point(0, 195);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(106, 37);
			this->buttonSave->TabIndex = 1;
			this->buttonSave->Text = L"Сохранить изменения";
			this->buttonSave->UseVisualStyleBackColor = false;
			this->buttonSave->Click += gcnew System::EventHandler(this, &Sem1::buttonSave_Click);
			// 
			// Sem1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(380, 232);
			this->Controls->Add(this->panelGrid);
			this->Name = L"Sem1";
			this->Text = L"Sem1";
			this->Load += gcnew System::EventHandler(this, &Sem1::Sem1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->panelGrid->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		void InitializeDataGridView()
		{
			dataGridView->AutoGenerateColumns = false;
			dataGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			DataGridViewTextBoxColumn^ subjectColumn = gcnew DataGridViewTextBoxColumn();
			subjectColumn->Name = "Subject";
			subjectColumn->HeaderText = "Предмет";
			dataGridView->Columns->Add(subjectColumn);

			array<String^>^ subjects = { "Algebra z geometria", 
				"Analiza matematyczna", 
				"Ergonomia", 
				"Podstawy informatyki", 
				"Probabilistyka i statystyka", 
				"BHP", 
				"Technologie informacyjne", 
				"Jezyk obcy", 
				"Wychowanie fizyczne", 
				"Zarzadzanie projektami",
				"Srednia ocena"
			};

			dataGridView->RowCount = subjects->Length;


			for (int i = 0; i < subjects->Length; ++i)
			{
				dataGridView->Rows[i]->Cells["Subject"]->Value = subjects[i];
			}

			DataGridViewTextBoxColumn^ typeColumn = gcnew DataGridViewTextBoxColumn();
			typeColumn->Name = "Type";
			typeColumn->HeaderText = "Тип";
			dataGridView->Columns->Add(typeColumn);

			array<String^>^ types = { "E",
				"E",
				"Z",
				"E",
				"Z",
				"Z",
				"Z",
				"Z",
				"Z",
				"P",
			};

			for (int i = 0; i < types->Length; ++i)
			{
				dataGridView->Rows[i]->Cells["Type"]->Value = types[i];
			}

			dataGridView->Columns["Subject"]->ReadOnly = true;
			dataGridView->Columns["Type"]->ReadOnly = true;


			DataGridViewTextBoxColumn^ gradeColumn = gcnew DataGridViewTextBoxColumn();
			gradeColumn->Name = "Grade";
			gradeColumn->HeaderText = "Оценка";
			gradeColumn->ValueType = Object::typeid;
			dataGridView->Columns->Add(gradeColumn);

			dataGridView->RowHeadersVisible = false;

			// Добавление DataGridView в panelGrid
			panelGrid->Controls->Add(dataGridView);

			subjectColumn->Width = 150; 
			typeColumn->Width = 70;   
			gradeColumn->Width = 70;   

		}

		void LoadDataFromFile() {
			if (File::Exists("grades.txt")) {
				array<String^>^ lines = File::ReadAllLines("grades.txt");
				int rowCount = Math::Min(lines->Length, dataGridView->Rows->Count);

				for (int i = 0; i < rowCount; i++) {
					dataGridView->Rows[i]->Cells["Grade"]->Value = lines[i];
				}
			}
		}

		void CalculateAverageGrade() {
			double sum = 0.0;
			double count = 0.0;

			for (int i = 0; i < dataGridView->Rows->Count - 1; ++i) {
				if (dataGridView->Rows[i]->Cells[2]->Value != nullptr) {
					String^ value = dataGridView->Rows[i]->Cells[2]->Value->ToString();
					double number;

					if (Double::TryParse(value, number)) {
						sum += number;
						count++;
					}
				}
			}

			if (count > 0) {
				double average = sum / count;
				dataGridView->Rows[dataGridView->Rows->Count - 1]->Cells[2]->Value = average.ToString("F2");
			}
			else {
				dataGridView->Rows[dataGridView->Rows->Count - 1]->Cells[2]->Value = "Нет данных";
			}
		}

#pragma endregion
private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
	StreamWriter^ sw = gcnew StreamWriter("grades.txt");

	try {
		for (int i = 0; i < dataGridView->Rows->Count; i++) {
			String^ grade = dataGridView->Rows[i]->Cells["Grade"]->Value ? dataGridView->Rows[i]->Cells["Grade"]->Value->ToString() : "";

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
	for each (DataGridViewRow ^ row in dataGridView->Rows) {
		row->Cells["Grade"]->Value = ""; // Установка пустого значения для третьего столбца
	}

	// Очистка текстового файла
	System::IO::File::WriteAllText("data.txt", "");
}
private: System::Void Sem1_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
