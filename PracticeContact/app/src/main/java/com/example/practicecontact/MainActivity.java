package com.example.practicecontact;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.menu_add) {
            // 点击"新增"，显示提示信息
            Toast.makeText(this, "增加一个联系人", Toast.LENGTH_SHORT).show();
            return true;

        } else if (id == R.id.menu_delete) {
            // 点击"删除"，弹出警告对话框
            new AlertDialog.Builder(this)
                    .setMessage("确定要删除吗？")
                    .setPositiveButton("确定", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            dialog.dismiss();
                        }
                    })
                    .setNegativeButton("取消", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            dialog.dismiss();
                        }
                    })
                    .show();
            return true;

        } else if (id == R.id.menu_exit) {
            // 点击"退出"，销毁当前活动
            finish();
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
