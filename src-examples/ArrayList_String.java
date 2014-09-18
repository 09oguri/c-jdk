import java.util.ArrayList;

public class ArrayList_String {

    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<String>(10);

        list.add(0, new String("C"));
        list.add(1, new String("C#"));
        list.add(2, new String("C++"));
        list.add(3, new String("Java"));
        list.add(4, new String("Perl"));
        list.add(5, new String("Python"));
        list.add(6, new String("Ruby"));

        int i;
        for (i = 0; i < list.size(); i++) {
            String lang = list.get(i);
            System.out.printf("%s\n", lang);
        }

        return;
    }

}
