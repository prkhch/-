import { createSlice, createAsyncThunk } from '@reduxjs/toolkit';
import * as authAPI from '../lib/api/auth';

interface UserState {
  user: any;
  checkError: Error | null;
}

const initialState: UserState = {
  user: null,
  checkError: null,
};

export const tempSetUser = createAsyncThunk('user/tempSetUser', async (user: any) => {
  return user;
});

export const check = createAsyncThunk('user/check', authAPI.check);

export const logout = createAsyncThunk('user/logout', async () => {
  try {
    await authAPI.logout();
    localStorage.removeItem('user');
  } catch (e) {
    console.log(e);
  }
});

const userSlice = createSlice({
  name: 'user',
  initialState,
  reducers: {},
  extraReducers: (builder) => {
    builder.addCase(tempSetUser.fulfilled, (state, action) => {
      state.user = action.payload;
    });
    builder.addCase(check.fulfilled, (state, action) => {
      state.user = action.payload;
    });
    builder.addCase(check.rejected, (state, action) => {
      state.user = null;
    });
    builder.addCase(logout.fulfilled, (state) => {
      state.user = null;
    });
  },
});

export default userSlice.reducer;
