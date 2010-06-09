Feature: Conversion
  Scenario Outline: Convert MGRS to latitude and longitude
    When I convert the MGRS "<mgrs>"
    Then I should be near "<location>"
    Then I should have the following result:
      | latitude   | longitude   |
      | <latitude> | <longitude> |
    Examples:
      | location          | mgrs            | latitude         | longitude        |
      | Boston, MA        | 19TCG3037191628 | 42.3584266010117 | -71.059781603146 |
      | San Francisco, CA | 10SEG5112981002 | 37.7749282053078 | -122.41941986071 |

  Scenario Outline: Convert latitude and longitude to MGRS
    When I convert the latitude and longitude "<latitude>,<longitude>"
    Then I should have the MGRS result <mgrs>
    Examples:
      | location          | mgrs            | latitude         | longitude        |
      | Boston, MA        | 19TCG3037191628 | 42.3584266010117 | -71.059781603146 |
      | San Francisco, CA | 10SEG5112981002 | 37.7749282053078 | -122.41941986071 |
