package com.example.a23520580_tranthanhhung_th4;

import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.AdapterView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private EditText etId;
    private EditText etName;
    private RadioGroup rgType;
    private Button btnNhap;
    private ListView lvPerson;
    private TextView tvSelection;

    private ArrayList<Employee> employees;
    private ArrayAdapter<Employee> adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        etId = findViewById(R.id.edittextMaNV);
        etName = findViewById(R.id.edittextTenNV);
        rgType = findViewById(R.id.rgType);
        btnNhap = findViewById(R.id.buttonNhap);
        lvPerson = findViewById(R.id.lvPerson);
        tvSelection = findViewById(R.id.tvSelection);

        employees = new ArrayList<>();
        employees.add(new EmployeeFulltime("m1", "NGuyen Thi Teo"));
        employees.add(new EmployeeParttime("m2", "Tran Van Ty"));

        adapter = new ArrayAdapter<>(
                this,
                android.R.layout.simple_list_item_1,
                employees
        );
        lvPerson.setAdapter(adapter);

        btnNhap.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addNewEmployee();
            }
        });
        lvPerson.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Employee e = adapter.getItem(position);       // lấy đúng kiểu
                tvSelection.setText("position: " + position + "; value = " + e);
            }
        });
        lvPerson.setOnItemLongClickListener((parent, view, position, id) -> {
            Employee removed = employees.remove(position);
            adapter.notifyDataSetChanged();
            tvSelection.setText("Đã xóa: "+ removed+"; position:"+position);
            return true;
        });

    }
    private void addNewEmployee() {
        int radId = rgType.getCheckedRadioButtonId();
        String id = etId.getText().toString().trim();
        String name = etName.getText().toString().trim();
        Employee employee;
        if (radId == R.id.rd_chinhthuc) {
            employee = new EmployeeFulltime(id, name);
        } else {
            employee = new EmployeeParttime(id, name);
        }
        employees.add(employee);
        etId.setText("");
        etName.setText("");
        rgType.clearCheck();

        lvPerson.post(() -> lvPerson.setSelection(adapter.getCount() - 1));
    }

    private static abstract class Employee {
        private final String id;
        private final String name;

        public Employee(String id, String name) {
            this.id = id;
            this.name = name;
        }

        public abstract double tinhLuong();

        @Override
        public String toString() {
            return id + " - " + name;
        }
    }
    private static class EmployeeFulltime extends Employee {
        private static final double SALARY = 500.0;
        public EmployeeFulltime(String id, String name) {
            super(id, name);
        }
        @Override
        public double tinhLuong() {
            return SALARY;
        }
        @Override
        public String toString() {
            return super.toString() + " -->FullTime=" + tinhLuong();
        }
    }
    private static class EmployeeParttime extends Employee {
        private static final double SALARY = 150.0;

        public EmployeeParttime(String id, String name) {
            super(id, name);
        }
        @Override
        public double tinhLuong() {
            return SALARY;
        }
        @Override
        public String toString() {
            return super.toString() + " -->PartTime=" + tinhLuong();
        }
    }
}
