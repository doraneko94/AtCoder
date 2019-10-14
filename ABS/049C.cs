using System;
class Program
{
    static void Main(string[] args) {
        string S = Console.ReadLine();
        int len = S.Length;
        int pos = 0;
        int flag = 0;
        while (pos < len) {
            if (pos+7 <= len && S.Substring(pos, 7)=="dreamer") {
                pos += 7;
                flag = 2;
            }
            else if (pos+6 <= len && S.Substring(pos, 6)=="eraser") {
                pos += 6;
                flag = 1;
            }
            else if (pos+5 <= len && S.Substring(pos, 5)=="dream") {
                pos += 5;
                flag = 0;
            }
            else if (pos+5 <= len && S.Substring(pos, 5)=="erase") {
                pos += 5;
                flag = 0;
            }
            else if (flag > 0) {
                pos -= flag;
                flag = 0;
            }
            else break;
        }
        if (pos==len) Console.WriteLine("YES");
        else Console.WriteLine("NO");

        return;
    }
}