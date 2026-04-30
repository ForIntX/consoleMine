# --- Değişkenler ---
CXX = g++
CXXFLAGS = -g -O0 -Wall -std=c++11
TARGET_DIR = output
TARGET = $(TARGET_DIR)/oyun_dosyasi

# Tüm kaynak dosyalarını bulur
SRCS = main.cpp $(wildcard source/*.cpp) $(wildcard source/mines/*.cpp) $(wildcard source/gamer/*.cpp) $(wildcard source/ai/*.cpp)
# Nesne dosyalarını (.o) output klasörü altında olacak şekilde eşler
# Örneğin: source/game.cpp -> output/source/game.o olur.
OBJS = $(SRCS:%.cpp=$(TARGET_DIR)/%.o)

# --- Kurallar ---

# Varsayılan kural
all: $(TARGET)

# Ana hedef: Nesne dosyalarını birleştirir
$(TARGET): $(OBJS)
	@echo "Dosyalar bağlanıyor: $@"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Nesne dosyalarını derleme kuralı
# Bu kural her .cpp için output klasörü içinde ilgili klasör yapısını koruyarak .o oluşturur
$(TARGET_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)  # Nesne dosyasının klasörü yoksa oluşturur (Örn: output/source/mines/)
	@echo "Derleniyor: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Temizlik kuralı: Sadece output klasörünü siler, kaynak kodlara dokunmaz
clean:
	rm -rf $(TARGET_DIR)
	@echo "Output klasörü temizlendi."

# Derle ve çalıştır
run: all
	./$(TARGET)