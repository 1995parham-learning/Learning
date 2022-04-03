package hello;

import java.util.List;

public class App {
    public App() {}

    public List<String> getFriends() {
      return List.of("Navid", "Mohammad");
    }

    public static void main(String[] args) {
      var app = new App();

      System.out.println(app.getFriends());
    }
}
