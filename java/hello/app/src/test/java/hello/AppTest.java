package hello;

import org.junit.jupiter.api.Test;
import java.util.List;
import static org.junit.jupiter.api.Assertions.*;

class AppTest {
    @Test void parhamHasFriends() {
      Person navid = new Person("Navid", "Mashayekhi");
      Person mohammad = new Person("Mohammad", "Mahboubi");
      Person parham = new Person("Parham", "Alvani");
      parham.addFriends(navid);
      parham.addFriends(mohammad);

      assertNotNull(parham.getFriends());
      assertEquals("Parham", parham.getFirstName());
      assertEquals("Alvani", parham.getLastName());
      assertEquals(List.of(navid, mohammad), parham.getFriends());
    }
}
