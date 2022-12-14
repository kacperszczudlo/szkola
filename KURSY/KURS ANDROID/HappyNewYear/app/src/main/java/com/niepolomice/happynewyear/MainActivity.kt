package com.niepolomice.happynewyear

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.*
import java.time.LocalDate
import java.time.Period
import java.time.format.DateTimeFormatter

class MainActivity : AppCompatActivity() {


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val imageView = findViewById<ImageView>(R.id.imageView)
        val button = findViewById<Button>(R.id.button)
        val myfirstName = findViewById<EditText>(R.id.editText)
        var friendTextView = findViewById<TextView>(R.id.friendTextView)
        imageView.setOnClickListener {
            Toast.makeText(this@MainActivity,getDaysToNewYear(),Toast.LENGTH_LONG)
                .show()
        }
        button.setOnClickListener {
           if(myfirstName.text.toString().trim()==""){
               friendTextView.setText("Brak danych")
           }else if(getMyFriends().contains(myfirstName.text.toString().trim())){
               friendTextView.setText("${myfirstName.text} to Twój znajomy")
           }else{
               friendTextView.setText("${myfirstName.text} to nie Twój znajomy")
           }
        }
    }

    private fun getDaysToNewYear():String {
        val today = LocalDate.now()
        val currentYear = (today.year+1).toString()
        var happy = LocalDate.parse("0101$currentYear",
            DateTimeFormatter.ofPattern("ddMMyyyy"))

        var period = Period.between(today,happy)
        val result:String=
            "Do nowego roku zostało: ${period.months} miesięcy oraz ${period.days} dni"
        return result
    }
    private fun getMyFriends():List<String>{
        return listOf("Adam","Roman","Edmund","Monika","Teresa","Anna")
    }
}