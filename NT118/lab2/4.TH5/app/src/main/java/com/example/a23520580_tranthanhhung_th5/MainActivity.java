package com.example.a23520580_tranthanhhung_th5;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private EditText etId;
    private EditText etName;
    private CheckBox cbManager;
    private Button btnAdd;
    private ListView lvEmployees;

    private ArrayList<Employee> employees;
    private EmployeeAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        etId = findViewById(R.id.etId);
        etName = findViewById(R.id.etName);
        cbManager = findViewById(R.id.cbManager);
        btnAdd = findViewById(R.id.btnAdd);
        lvEmployees = findViewById(R.id.lvEmployees);

        employees = new ArrayList<>();
        adapter = new EmployeeAdapter(this, R.layout.item_employee, employees);
        lvEmployees.setAdapter(adapter);

        btnAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addEmployee();
            }
        });

        lvEmployees.setOnItemLongClickListener((parent, view, position, id) -> {
            Employee removed = employees.remove(position);
            adapter.notifyDataSetChanged();
            return true;
        });
    }

    private void addEmployee() {
        String id = etId.getText().toString().trim();
        String name = etName.getText().toString().trim();
        boolean isManager = cbManager.isChecked();

        employees.add(new Employee(id, name, isManager));
        adapter.notifyDataSetChanged();

        etId.setText("");
        etName.setText("");
        cbManager.setChecked(false);

        lvEmployees.post(new Runnable() {
            @Override
            public void run() {
                lvEmployees.setSelection(adapter.getCount() - 1);
            }
        });
    }

    public static class Employee {
        private final String id;
        private final String fullName;
        private final boolean manager;

        public Employee(String id, String fullName, boolean manager) {
            this.id = id;
            this.fullName = fullName;
            this.manager = manager;
        }

        public String getId() {
            return id;
        }

        public String getFullName() {
            return fullName;
        }

        public boolean isManager() {
            return manager;
        }
    }

    public static class EmployeeAdapter extends ArrayAdapter<Employee> {

        public EmployeeAdapter(AppCompatActivity context, int layoutId, List<Employee> objects) {
            super(context, layoutId, objects);
        }

        private static class ViewHolder {
            LinearLayout llParent;
            TextView tvFullName;
            TextView tvPosition;
            ImageView ivManager;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            ViewHolder h;
            if (convertView == null) {
                convertView = LayoutInflater.from(getContext()).inflate(R.layout.item_employee, parent, false);
                h = new ViewHolder();
                h.llParent = convertView.findViewById(R.id.item_employee_ll_parent);
                h.tvFullName = convertView.findViewById(R.id.item_employee_tv_fullname);
                h.tvPosition = convertView.findViewById(R.id.item_employee_tv_position);
                h.ivManager = convertView.findViewById(R.id.item_employee_iv_manager);
                convertView.setTag(h);
            } else {
                h = (ViewHolder) convertView.getTag();
            }
            Employee e = getItem(position);
            if (e != null && e.getFullName() != null) {
                h.tvFullName.setText(e.getFullName());
            } else {
                h.tvFullName.setText("");
            }
            if (e != null && e.isManager()) {
                h.ivManager.setVisibility(View.VISIBLE);
                h.tvPosition.setVisibility(View.GONE);
            } else {
                h.ivManager.setVisibility(View.GONE);
                h.tvPosition.setVisibility(View.VISIBLE);
                h.tvPosition.setText(getContext().getString(R.string.staff));
            }
            int color = (position % 2 == 0)
                    ? ContextCompat.getColor(getContext(), R.color.white)
                    : ContextCompat.getColor(getContext(), R.color.light_blue);
            h.llParent.setBackgroundColor(color);
            return convertView;
        }
    }
}
