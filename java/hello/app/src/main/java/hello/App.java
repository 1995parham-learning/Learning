package hello;

public class App {
    public static void main(String[] args) {
      Person navid = new Person("Navid", "Mashayekhi");
      Person mohammad = new Person("Mohammad", "Mahboubi");
      Person parham = new Person("Parham", "Alvani");
      parham.addFriends(navid);
      parham.addFriends(mohammad);

      System.out.println(parham);
    }
}
