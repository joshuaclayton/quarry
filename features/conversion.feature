Feature: Conversion
  Scenario: Convert MGRS to latitude and longitude
    When I convert the MGRS "38SLB8359589597"
    Then I should have the following result:
      | latitude  | 33.3392619738408 |
      | longitude | 43.7491353591999 |
