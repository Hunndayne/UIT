package com.example.a23520580_tranthanhhung_5;


import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private EditText etName;
    private Spinner spThumbnail;
    private CheckBox cbPromo;
    private Button btnAdd;
    private GridView gvDishes;

    private ArrayList<Dish> dishes;
    private DishAdapter dishAdapter;
    private ThumbnailAdapter thumbAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        etName = findViewById(R.id.etName);
        spThumbnail = findViewById(R.id.spThumbnail);
        cbPromo = findViewById(R.id.cbPromo);
        btnAdd = findViewById(R.id.btnAdd);
        gvDishes = findViewById(R.id.gvDishes);

        thumbAdapter = new ThumbnailAdapter(Thumbnail.values());
        spThumbnail.setAdapter(thumbAdapter);
        spThumbnail.setSelection(0);

        dishes = new ArrayList<>();
        dishAdapter = new DishAdapter(dishes);
        gvDishes.setAdapter(dishAdapter);

        btnAdd.setOnClickListener(v -> addDish());

        gvDishes.setOnItemClickListener((AdapterView<?> parent, View view, int position, long id) -> {
            Dish d = dishes.get(position);
            Toast.makeText(this, d.name + (d.promo ? " (Promo)" : ""), Toast.LENGTH_SHORT).show();
        });
    }

    private void addDish() {
        String name = etName.getText().toString().trim();
        if (name.isEmpty()) {
            etName.setError("Nhập tên món");
            return;
        }
        Thumbnail t = (Thumbnail) spThumbnail.getSelectedItem();
        boolean promo = cbPromo.isChecked();

        dishes.add(new Dish(name, t, promo));
        dishAdapter.notifyDataSetChanged();

        etName.setText("");
        spThumbnail.setSelection(0);
        cbPromo.setChecked(false);
        Toast.makeText(this, "Added successfully", Toast.LENGTH_SHORT).show();
    }

    public enum Thumbnail {
        THUMB1("Thumbnail 1", R.drawable.img1),
        THUMB2("Thumbnail 2", R.drawable.img2),
        THUMB3("Thumbnail 3", R.drawable.img3);

        private final String label;
        private final int resId;

        Thumbnail(String name, int imgRes) {
            this.label = name;
            this.resId = imgRes;
        }

        public String getLabel() { return label; }

        public int getResId() { return resId; }
    }

    public static class Dish {
        public final String name;
        public final Thumbnail thumb;
        public final boolean promo;

        public Dish(String name, Thumbnail thumb, boolean promo) {
            this.name = name;
            this.thumb = thumb;
            this.promo = promo;
        }
    }

    private class DishAdapter extends BaseAdapter {
        private final List<Dish> data;

        DishAdapter(List<Dish> data) {
            this.data = data;
        }

        @Override
        public int getCount() { return data.size(); }

        @Override
        public Dish getItem(int position) { return data.get(position); }

        @Override
        public long getItemId(int position) { return position; }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            DishViewHolder h;
            if (convertView == null) {
                convertView = LayoutInflater.from(MainActivity.this)
                        .inflate(R.layout.item_dish, parent, false);
                h = new DishViewHolder();
                h.img = convertView.findViewById(R.id.imgThumb);
                h.name = convertView.findViewById(R.id.tvDishName);
                h.star = convertView.findViewById(R.id.imgStar);
                convertView.setTag(h);
            } else {
                h = (DishViewHolder) convertView.getTag();
            }

            Dish d = getItem(position);
            h.img.setImageResource(d.thumb.getResId());
            h.name.setText(d.name);
            h.name.setSelected(true); // enable marquee
            h.star.setVisibility(d.promo ? View.VISIBLE : View.GONE);
            return convertView;
        }

        class DishViewHolder {
            ImageView img;
            TextView name;
            ImageView star;
        }
    }

    private class ThumbnailAdapter extends ArrayAdapter<Thumbnail> {
        ThumbnailAdapter(Thumbnail[] items) {
            super(MainActivity.this, R.layout.item_selected_thumbnail, items);
            setDropDownViewResource(R.layout.item_thumbnail);
        }

        @Override
        public View getDropDownView(int position, View convertView, ViewGroup parent) {
            // Hiển thị dialog list: ảnh + tên
            View v = convertView;
            if (v == null) {
                v = LayoutInflater.from(getContext()).inflate(R.layout.item_thumbnail, parent, false);
            }
            Thumbnail t = getItem(position);
            ImageView iv = v.findViewById(R.id.ivThumb);
            TextView tv = v.findViewById(R.id.tvThumbName);
            if (t != null) {
                iv.setImageResource(t.getResId());
                tv.setText(t.getLabel());
            }
            return v;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            // View hiển thị khi spinner đóng: chỉ tên
            View v = convertView;
            if (v == null) {
                v = LayoutInflater.from(getContext()).inflate(R.layout.item_selected_thumbnail, parent, false);
            }
            TextView tv = v.findViewById(R.id.tvSelected);
            Thumbnail t = getItem(position);
            tv.setText(t != null ? t.getLabel() : "");
            return v;
        }
    }
}