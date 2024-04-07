#include "Data.hpp"
#include "Serializer.hpp"

void graphicsRepresnationOfSerialization() {
  std::cout << "\nSerialization and Deserialization Process:\n\n";

  // Step 1: Initial State
  std::cout << "Step 1: Initial State\n";
  std::cout << "  [myData] - Instance of Data\n";
  std::cout << "      +-----------------+\n";
  std::cout << "      |     Data        |\n";
  std::cout << "      +-----------------+\n";
  std::cout << "      |   (content)     |\n";
  std::cout << "      +-----------------+\n\n";

  // Step 2: After Serialization
  std::cout << "Step 2: After Serialization (to uintptr_t)\n";
  std::cout << "      +-----------------+     +-----------------+\n";
  std::cout << "      |     Data        |     |   uintptr_t     |\n";
  std::cout << "      +-----------------+     +-----------------+\n";
  std::cout << "      |   (content)     | --> |   (address)     |\n";
  std::cout << "      +-----------------+     +-----------------+\n\n";

  // Step 3: After Deserialization
  std::cout << "Step 3: After Deserialization (back to Data*)\n";
  std::cout << "      +-----------------+     +-----------------+     "
               "+-----------------+\n";
  std::cout << "      |     Data        |     |   uintptr_t     |     |     "
               "Data*       |\n";
  std::cout << "      +-----------------+     +-----------------+     "
               "+-----------------+\n";
  std::cout << "      |   (content)     | <-- |   (address)     | <-- |   "
               "(points to)   |\n";
  std::cout << "      +-----------------+     +-----------------+     "
               "+-----------------+\n\n";
}

void testBasic() {
  Data myData;

  std::cout << "\n+---------------------------------------+\n";
  std::cout << "|             Basic Test                |\n";
  std::cout << "+---------------------------------------+\n\n";

  uintptr_t serializedData = Serializer::serialize(&myData);
  Data *deserializedData = Serializer::deserialize(serializedData);

  std::cout << "& myData:         " << &myData << std::endl;
  std::cout << "serializeData:    " << std::hex << serializedData << std::endl;
  std::cout << "deserializedData: " << deserializedData << std::endl;
  std::cout << std::endl;
}

void testNullPointer() {

  std::cout << "\n+---------------------------------------+\n";
  std::cout << "|        Test for NULL Pointer          |\n";
  std::cout << "+---------------------------------------+\n\n";
  Data *nullDataPtr = NULL;
  uintptr_t serializedNull = Serializer::serialize(nullDataPtr);
  Data *deserializedNull = Serializer::deserialize(serializedNull);

  if (deserializedNull == NULL) {
    std::cout << "Null pointer test passed.\n" << std::endl;
  } else {
    std::cout << "Null pointer test failed.\n" << std::endl;
  }
}

void testChangeDataMemberValue() {
  Data myData;
  myData.isSerialized = false;

  std::cout << "\n+---------------------------------------+\n";
  std::cout << "| Test for Changing DATA member value   |\n";
  std::cout << "+---------------------------------------+\n\n";
  uintptr_t serializedData = Serializer::serialize(&myData);
  myData.isSerialized = true;
  Data *deserializedData = Serializer::deserialize(serializedData);

  if (deserializedData->isSerialized == myData.isSerialized) {
    std::cout << "Changing data value test passed.\n" << std::endl;
  } else {
    std::cout << "Changin data value test failed.\n" << std::endl;
  }
  std::cout << "& myData:        " << &myData << std::endl;
  std::cout << "serializeData:   " << std::hex << serializedData << std::endl;
  std::cout << "deserializeData: " << deserializedData << std::endl;
  std::cout << std::endl;
}

void testMultipleObjects() {
  Data dataOne;
  Data dataTwo;

  std::cout << "\n+---------------------------------------+\n";
  std::cout << "|     Test with Multiple Data Objects     |\n";
  std::cout << "+---------------------------------------+\n\n";
  dataOne.isSerialized = true;
  dataTwo.isSerialized = false;

  uintptr_t serializedOne = Serializer::serialize(&dataOne);
  uintptr_t serializedTwo = Serializer::serialize(&dataTwo);

  Data *deserializedOne = Serializer::deserialize(serializedOne);
  Data *deserializedTwo = Serializer::deserialize(serializedTwo);

  std::cout << "Values for data One\n"
            << "\n"
            << "& data One:          " << &dataOne << "\n"
            << "serializeData One:   " << std::hex << serializedOne << "\n"
            << "deserializeData One: " << deserializedOne << std::endl;
  std::cout << std::endl;

  std::cout << "Values for data Two\n"
            << "\n"
            << "& data Two:          " << &dataTwo << "\n"
            << "serializeData Two:   " << std::hex << serializedTwo << "\n"
            << "deserializeData Two: " << deserializedTwo << std::endl;
  std::cout << std::endl;
}

int main() {
  graphicsRepresnationOfSerialization();

  testBasic();
  testNullPointer();
  testChangeDataMemberValue();
  testMultipleObjects();
  return 0;
}
