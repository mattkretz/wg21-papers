using floatv = native_simd<float>;
void f() {
  alignas(memory_alignment_v<floatv>) float data[N];
  fill_data(data);
  size_t i = 0;
  for (; i + floatv::size() <= N; i += floatv::size()) {
    floatv v(&data[i], flags::vector_aligned);
    where(v > 100.f, v) = 100.f + (v - 100.f) * 0.1f;
    v.memstore(&data[i], flags::vector_aligned);
  }
  for (; i < N; ++i) {
    float x = data[i];
    if (x > 100.f) {
      x = 100.f + (x - 100.f) * 0.1f;
    }
    data[i] = x;
  }
}

// ----------------- 8< ---------------------
