package hello;

import java.util.ArrayList;
import java.util.List;

public class App {
    private List<String> friends;

    public App() {
      this.friends = new ArrayList<>();
      this.friends.addAll(List.of("Navid", "Mohammad"));
    }

    public List<String> getFriends() {
      return this.friends;
    }

    public void addFriends(String name) {
      this.friends.add(name);
    }

    public static void main(String[] args) {
      var app = new App();

      System.out.println(app.getFriends());
    }
}
