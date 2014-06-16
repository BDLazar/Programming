using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Speech;
using System.Speech.Synthesis;
using System.Xml;,
using System.Xml.Linq;

/*Uses words,whole sentences and even a whole page.
 * Every time he receives a sentence,he will learn new words and generates an aswer.
 * Every time the program will shut down DANI will lose the data and starts again from 0(no knowledge).
 * */

namespace D.A.N.I.by_Bianca
{

    public partial class Form1 : Form
    {
        String phrase = "";
        int id = 0;
        word[] words = new word[5000000];//words
        link[] links = new link[5000000];//links
        
        public Form1()
        {
            InitializeComponent();
            progres_bar_on();
            textBox1.ResetText();
            textBox1.AppendText("Awaiting data ...");
            for (int i = 0; i < 5000000; i++)
            {
                words[i] = new word();
                links[i] = new link();
            }
        }

        //Initialization speech synthesizer (offered by ms. windows .net libraries )
        SpeechSynthesizer reader = new SpeechSynthesizer();

        //Send to D.A.N.I.button takes the entered text and divide it in words and then each word is put in database
        //Then generates an answer
        private void button1_Click(object sender, EventArgs e)
        {
            if (richTextBox1.Text != "")
            {
                
                string input_sentence = richTextBox1.Text;//get the entered sentence in text box
                textBox1.ResetText();
                textBox1.AppendText("Procesing data ...");
                add_words(input_sentence);               //call the function(method) add_words which will add the words in memory
                textBox1.ResetText();
                textBox1.AppendText("Generating phrase ...");
                phrase = form_phrase();                  //call function(method) form_phrase which creates the function after defaults rules with the words from memory
                richTextBox2.AppendText(" ");
                richTextBox2.AppendText(phrase);        //display created sentence
                update_data1();
                update_data2();
                reader.Dispose();
                reader = new SpeechSynthesizer();
                reader.Rate = -2;
                reader.SpeakAsync(phrase);//D.A.N.I. reads the sentence out loud
                textBox1.ResetText();
                textBox1.AppendText("Awaiting data ...");
                
            }
                //in case that i didnt put anything at the start it will tell me to put in data
            else
            {
                reader.Dispose();
                reader = new SpeechSynthesizer();
                reader.SpeakAsync("Please send me data.");
                MessageBox.Show("Please send me data.");
            }
        }

        //update method table1 words
        void update_data1() 
        { 
            richTextBox3.ResetText();
            richTextBox3.AppendText(" ");
            for (int i = 0; i < 5000000; i++)
            {
                if (words[i].id != -1)
                {
                    richTextBox3.AppendText("\n" + words[i].w + "\n");
                }
            }
        }
        //update method table2 links
        void update_data2()
        {
            richTextBox4.ResetText();
            richTextBox4.AppendText("\n"+"ID   "+"ID_LINK    "+"COUNTS_LINK"+"\n");
            for (int i = 0; i < 5000000; i++)
            {
                if (links[i].id !=-1 && links[i].id_link!=-1)
                {
                    richTextBox4.AppendText("\n  " + links[i].id + "   " + links[i].id_link + "                   " + links[i].counts_link + "\n");
                }
            }
        }

        //method that adds new words in database 
        void add_words(string phrase)
        {
           
            char[] delimiterChars = { ' ', ',', '.', ':', '\t', '!', '?', ';'};
            string[] words1 = phrase.Split(delimiterChars);
           
            for (int i = 0; i < words1.Length; i++)
            {

                if (false == check_word(words1[i]))
                {
                    words[id].id = id;
                    words[id].w = words1[i];
                    words[id].counts = words[id].counts + 1;
                    

                    if (id != 0 && false == check_link(id - 1, id))
                    {
                        links[id].id = id - 1;
                        links[id].id_link = id;
                        links[id].counts_link = 1;
                    }
                    else if(id!=0 && true == check_link(id - 1, id)) 
                    {
                        int temp2 = get_link_id(id - 1, id);
                        if (temp2 != -1)
                        {
                            links[temp2].counts_link = links[temp2].counts_link + 1;
                        }
                    }
                    id = id + 1;
                }
                else 
                {
                    int temp=get_id(words1[i]);
                    if (temp != -1)
                    {
                        words[temp].counts = words[temp].counts + 1;
                    }

                    if (temp != 0 && true == check_link(temp-1, temp))
                    {

                        links[temp].counts_link = links[temp].counts_link + 1;
                        
                    }


                }

            }

        }

        //method which turns on the progress bar(the green bar that moves)
        void progres_bar_on()
        {
            progressBar1.Style = ProgressBarStyle.Marquee;
            progressBar1.MarqueeAnimationSpeed = 30;
        }
        //stops the progress bar
        void progres_bar_off()
        {
            progressBar1.Style = ProgressBarStyle.Continuous;
            progressBar1.MarqueeAnimationSpeed = 0;
        }
        
        class word
        {
             public int id;
             public string w;
             public int counts;

            // constructor
            public word()
            {
                id = -1;
                w = "N/A";
                counts=0;
            }

        }

        class link
        {
            public int id;
            public int id_link;
            public int counts_link;

            // constructor
            public link()
            {
                id = -1;
                id_link = -1;
                counts_link = -1;
            }
        }

        //check_word method which checks if exists a word identical with the word that it is at when inserts words in database
        Boolean check_word(string word) 
       
        {
            for (int i = 0; i < 5000000; i++)
            {
                if(words[i].w==word)
                {
                    return true;
                }
            }
            return false;
        }

        //check_link method which checks if exists a link between two words
        Boolean check_link(int id,int id_link)
        {
            for (int i = 0; i < 5000000; i++)
            {
                if (links[i].id == id && links[i].id_link==id_link)
                {
                    return true;
                }
            }
            return false;
        }

        
        int get_id(string word)
        {
           for (int i = 0; i < 5000000; i++)
            {
                if (words[i].w == word)
                {
                   return words[i].id; ;
                }
            }
            return -1;
        }

        int get_link_id(int id, int id_link)
        {
           for (int i = 0; i < 5000000; i++)
            {
                if (links[i].id == id && links[i].id_link == id_link)
                {
                   return i;
                }
            }
            return -1;
        }

        //method that creates the sentence
        string form_phrase() 
        
        {
            string phrase="";
            Random r = new Random();
            int random_word = r.Next(0,id);
            bool is_a_next_word=true;
            phrase=words[random_word].w;
            while (is_a_next_word) 
            {

                int aux = next_word(random_word);
                if (aux != -1)
                {
                    phrase = phrase + " " + words[aux].w;
                    random_word = aux;
                }
                else 
                {
                    is_a_next_word = false;
                }
            }


            return phrase;
        }

        int next_word(int current_word)
        {
            int next_word=-1;
            int maxc_count=0;
           
            for (int i = 0; i < 5000000; i++)
            {
                if (links[i].id == current_word && links[i].counts_link>maxc_count)
                {
                    maxc_count = links[i].counts_link;
                    next_word = links[i].id_link;    
                }
            }

            return next_word;
        
        }

    }

}
