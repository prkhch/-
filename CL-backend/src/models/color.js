import mongoose from 'mongoose';

const { Schema } = mongoose;

const ColorSchema = new Schema({
  hex: {
    type: String,
    required: true,
  },
  R: {
    type: Number,
    required: true,
    min: 0,
    max: 255,
  },
  G: {
    type: Number,
    required: true,
    min: 0,
    max: 255,
  },
  B: {
    type: Number,
    required: true,
    min: 0,
    max: 255,
  },
  likes: {
    type: Number,
    default: 0,
  },
});

const Color = mongoose.model('Color', ColorSchema);

export default Color;
