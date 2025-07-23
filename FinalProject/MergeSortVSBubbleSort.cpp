#pragma once

namespace StudentResultOrganizer {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    public ref class Student {
    public:
        String^ name;
        int score;
    };

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
            students = gcnew List<Student^>();
        }

    protected:
        ~MainForm()
        {
            if (components)
                delete components;
        }

    private:
        System::ComponentModel::Container^ components;

        // UI elements
        Label^ lblName;
        Label^ lblScore;
        TextBox^ txtName;
        TextBox^ txtScore;
        Button^ btnAdd;
        Button^ btnSort;
        ListBox^ lstBubbleResults;
        ListBox^ lstMergeResults;
        Label^ lblBubbleTitle;
        Label^ lblMergeTitle;
        Label^ lblSteps;

        // Student list
        List<Student^>^ students;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->SuspendLayout();
            this->Text = L"Student Result Organizer";
            this->ClientSize = System::Drawing::Size(750, 550);
            this->BackColor = Color::MistyRose;

            // Label: Student Name
            this->lblName = gcnew Label();
            this->lblName->Text = "Student Name:";
            this->lblName->Location = Point(220, 20);
            this->lblName->Size = Drawing::Size(100, 20);
            this->lblName->BackColor = Color::Transparent;
            this->Controls->Add(this->lblName);

            // TextBox: Name
            this->txtName = gcnew TextBox();
            this->txtName->Location = Point(330, 20);
            this->txtName->Size = Drawing::Size(130, 20);
            this->Controls->Add(this->txtName);

            // Label: Score
            this->lblScore = gcnew Label();
            this->lblScore->Text = "Score:";
            this->lblScore->Location = Point(220, 50);
            this->lblScore->Size = Drawing::Size(100, 20);
            this->lblScore->BackColor = Color::Transparent;
            this->Controls->Add(this->lblScore);

            // TextBox: Score
            this->txtScore = gcnew TextBox();
            this->txtScore->Location = Point(330, 50);
            this->txtScore->Size = Drawing::Size(130, 20);
            this->Controls->Add(this->txtScore);

            // Add Student Button
            this->btnAdd = gcnew Button();
            this->btnAdd->Text = "Add Student";
            this->btnAdd->Location = Point(270, 90);
            this->btnAdd->Click += gcnew EventHandler(this, &MainForm::btnAdd_Click);
            this->Controls->Add(this->btnAdd);

            // Sort Button
            this->btnSort = gcnew Button();
            this->btnSort->Text = "Sort Results";
            this->btnSort->Location = Point(380, 90);
            this->btnSort->Click += gcnew EventHandler(this, &MainForm::btnSort_Click);
            this->Controls->Add(this->btnSort);

            // Bubble Sort Title
            this->lblBubbleTitle = gcnew Label();
            this->lblBubbleTitle->Text = "Bubble Sort";
            this->lblBubbleTitle->Location = Point(200, 150);
            this->lblBubbleTitle->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            this->Controls->Add(this->lblBubbleTitle);

            // ListBox: Bubble Sort Results
            this->lstBubbleResults = gcnew ListBox();
            this->lstBubbleResults->Location = Point(120, 180);
            this->lstBubbleResults->Size = Drawing::Size(250, 200);
            this->lstBubbleResults->BackColor = Color::LavenderBlush;
            this->Controls->Add(this->lstBubbleResults);

            // Merge Sort Title
            this->lblMergeTitle = gcnew Label();
            this->lblMergeTitle->Text = "Merge Sort";
            this->lblMergeTitle->Location = Point(500, 150);
            this->lblMergeTitle->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            this->Controls->Add(this->lblMergeTitle);

            // ListBox: Merge Sort Results
            this->lstMergeResults = gcnew ListBox();
            this->lstMergeResults->Location = Point(420, 180);
            this->lstMergeResults->Size = Drawing::Size(250, 200);
            this->lstMergeResults->BackColor = Color::Honeydew;
            this->Controls->Add(this->lstMergeResults);

            // Steps Label
            this->lblSteps = gcnew Label();
            this->lblSteps->Location = Point(20, 400);
            this->lblSteps->Size = Drawing::Size(700, 30);
            this->lblSteps->Text = "Steps Taken:";
            this->lblSteps->Font = gcnew Drawing::Font("Segoe UI", 9, FontStyle::Italic);
            this->Controls->Add(this->lblSteps);

            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        void btnAdd_Click(Object^ sender, EventArgs^ e)
        {
            String^ name = txtName->Text;
            int score;

            if (name == "" || !Int32::TryParse(txtScore->Text, score)) {
                MessageBox::Show("Please enter a valid name and score.");
                return;
            }

            Student^ s = gcnew Student();
            s->name = name;
            s->score = score;
            students->Add(s);

            txtName->Clear();
            txtScore->Clear();

            MessageBox::Show("Student added!");
        }

        void btnSort_Click(Object^ sender, EventArgs^ e)
        {
            if (students->Count == 0) {
                MessageBox::Show("No students to sort.");
                return;
            }

            int bubbleSteps = 0;
            int mergeSteps = 0;

            auto bubbleWatch = System::Diagnostics::Stopwatch::StartNew();
            List<Student^>^ bubbleSorted = gcnew List<Student^>(students);
            BubbleSort(bubbleSorted, bubbleSteps);
            bubbleWatch->Stop();

            auto mergeWatch = System::Diagnostics::Stopwatch::StartNew();
            List<Student^>^ mergeSorted = gcnew List<Student^>(students);
            mergeSorted = MergeSort(mergeSorted, mergeSteps);
            mergeWatch->Stop();

            lstBubbleResults->Items->Clear();
            lstMergeResults->Items->Clear();

            for each (Student ^ s in bubbleSorted)
                lstBubbleResults->Items->Add(s->name + " - " + s->score);

            for each (Student ^ s in mergeSorted)
                lstMergeResults->Items->Add(s->name + " - " + s->score);

            double bubbleSeconds = bubbleWatch->Elapsed.TotalSeconds;
            double mergeSeconds = mergeWatch->Elapsed.TotalSeconds;

            lblSteps->Text = String::Format("Bubble Sort Steps: {0} | Time: {1:F6}s    ||    Merge Sort Steps: {2} | Time: {3:F6}s",
                bubbleSteps, bubbleSeconds, mergeSteps, mergeSeconds);
        }

        void BubbleSort(List<Student^>^ list, int% steps)
        {
            steps = 0;
            int n = list->Count;
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    steps++;
                    if (list[j]->score < list[j + 1]->score) {
                        Student^ temp = list[j];
                        list[j] = list[j + 1];
                        list[j + 1] = temp;
                    }
                }
            }
        }

        List<Student^>^ MergeSort(List<Student^>^ list, int% steps)
        {
            steps++;
            if (list->Count <= 1)
                return list;

            int mid = list->Count / 2;
            List<Student^>^ left = list->GetRange(0, mid);
            List<Student^>^ right = list->GetRange(mid, list->Count - mid);

            left = MergeSort(left, steps);
            right = MergeSort(right, steps);

            return Merge(left, right, steps);
        }

        List<Student^>^ Merge(List<Student^>^ left, List<Student^>^ right, int% steps)
        {
            List<Student^>^ result = gcnew List<Student^>();
            int i = 0, j = 0;

            while (i < left->Count && j < right->Count) {
                steps++;
                if (left[i]->score >= right[j]->score)
                    result->Add(left[i++]);
                else
                    result->Add(right[j++]);
            }

            while (i < left->Count) result->Add(left[i++]);
            while (j < right->Count) result->Add(right[j++]);

            return result;
        }
    };
}
