package com.example.a23520580_tranthanhhung_th5;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.recyclerview.widget.SimpleItemAnimator; // thêm nếu bạn muốn tắt riêng change-anim

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private EditText etId;
    private EditText etName;
    private CheckBox cbManager;
    private Button btnAdd;
    private RecyclerView rvEmployees;

    private ArrayList<Employee> employees;
    private EmployeeAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etId = findViewById(R.id.etId);
        etName = findViewById(R.id.etName);
        cbManager = findViewById(R.id.cbManager);
        btnAdd = findViewById(R.id.btnAdd);
        rvEmployees = findViewById(R.id.rvEmployees);

        employees = new ArrayList<>();
        setupRecyclerView();

        btnAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addEmployee();
            }
        });
    }

    private void setupRecyclerView() {
        rvEmployees.setLayoutManager(new LinearLayoutManager(this));

        adapter = new EmployeeAdapter(employees);
        adapter.setHasStableIds(true);
        rvEmployees.setAdapter(adapter);
        adapter.setOnItemLongClickListener(new EmployeeAdapter.OnItemLongClickListener() {
            @Override
            public void onItemLongClick(Employee employee, int position) {
                if (position == RecyclerView.NO_POSITION) {
                    return;
                }
                employees.remove(position);
                adapter.notifyItemRemoved(position);
            }
        });
    }

    private void addEmployee() {
        String id = etId.getText().toString().trim();
        String name = etName.getText().toString().trim();
        boolean isManager = cbManager.isChecked();

        employees.add(new Employee(id, name, isManager));
        int last = employees.size() - 1;
        adapter.notifyItemInserted(last);
        etId.setText("");
        etName.setText("");
        cbManager.setChecked(false);
        etId.requestFocus();

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

        public String getId() { return id; }

        public String getFullName() { return fullName; }

        public boolean isManager() { return manager; }
    }

    public static class EmployeeAdapter extends RecyclerView.Adapter<EmployeeAdapter.EmployeeViewHolder> {
        private final List<Employee> employees;
        private OnItemLongClickListener longClickListener;

        public interface OnItemLongClickListener {
            void onItemLongClick(Employee employee, int position);
        }

        public EmployeeAdapter(List<Employee> employees) {
            this.employees = employees;
        }

        public void setOnItemLongClickListener(OnItemLongClickListener listener) {
            this.longClickListener = listener;
        }

        @NonNull
        @Override
        public EmployeeViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext())
                    .inflate(R.layout.item_employee, parent, false);
            return new EmployeeViewHolder(view, this);
        }

        @Override
        public void onBindViewHolder(@NonNull EmployeeViewHolder holder, int position) {
            holder.bind(employees.get(position));
        }

        @Override
        public int getItemCount() {
            return employees.size();
        }
        @Override
        public long getItemId(int position) {
            // Stable ID từ hash của chuỗi id (đủ tốt cho demo)
            return employees.get(position).getId().hashCode();
        }
        public class EmployeeViewHolder extends RecyclerView.ViewHolder {
            private final LinearLayout llParent;
            private final TextView tvFullName;
            private final TextView tvPosition;
            private final ImageView ivManager;
            public EmployeeViewHolder(@NonNull View itemView, EmployeeAdapter adapter) {
                super(itemView);
                llParent = itemView.findViewById(R.id.item_employee_ll_parent);
                tvFullName = itemView.findViewById(R.id.item_employee_tv_fullname);
                tvPosition = itemView.findViewById(R.id.item_employee_tv_position);
                ivManager = itemView.findViewById(R.id.item_employee_iv_manager);

                itemView.setOnLongClickListener(v -> {
                    if (longClickListener != null) {
                        int pos = getBindingAdapterPosition();
                        if (pos != RecyclerView.NO_POSITION) {
                            longClickListener.onItemLongClick(employees.get(pos), pos);
                            return true;
                        }
                    }
                    return false;
                });
            }
            public void bind(Employee employee) {
                tvFullName.setText(employee.getFullName() == null ? "" : employee.getFullName());

                if (employee.isManager()) {
                    ivManager.setVisibility(View.VISIBLE);
                    tvPosition.setVisibility(View.GONE);
                } else {
                    ivManager.setVisibility(View.GONE);
                    tvPosition.setVisibility(View.VISIBLE);
                    tvPosition.setText(itemView.getContext().getString(R.string.staff));
                }
                int pos = getBindingAdapterPosition();
                if (pos == RecyclerView.NO_POSITION) pos = 0;

                int color = (pos % 2 == 0)
                        ? ContextCompat.getColor(itemView.getContext(), R.color.white)
                        : ContextCompat.getColor(itemView.getContext(), R.color.light_blue);
                llParent.setBackgroundColor(color);
            }

        }
    }
}
