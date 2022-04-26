package hello;

import java.util.List;
import java.util.ArrayList;

class Person {
  private String firstName;
  private String lastName;
  private List<Person> friends;

  public List<Person> getFriends() {
    return this.friends;
  }

  public void addFriends(Person p) {
    this.friends.add(p);
  }

  public String getLastName() {
      return lastName;
  }

  public String getFirstName() {
      return firstName;
  }

  @Override
  public String toString() {
      return String.format("%s %s %s", this.firstName, this.lastName, this.friends.toString());
  }

  public Person(String firstName, String lastName) {
      this.friends = new ArrayList<>();
      this.firstName = firstName;
      this.lastName = lastName;
  }
}
